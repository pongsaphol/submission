import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class grader {
  public static void main(String[] args) throws IOException {
    combo_lib.run();
  }
}

class combo_lib {
  private static final int MAX_NUM_MOVES = 8000;

  private static int N;
  private static String S;

  private static int num_moves;

  static int press(String p) {
    if (++num_moves > MAX_NUM_MOVES) {
      wrong_answer("too many moves");
    }
    int len = p.length();
    if (len > 4 * N) {
      wrong_answer("invalid press");
    }
    for (int i = 0; i < len; ++i) {
      char c = p.charAt(i);
      if (c != 'A' && c != 'B' && c != 'X' && c != 'Y') {
        wrong_answer("invalid press");
      }
    }
    int coins = 0;
    for (int i = 0, j = 0; i < len; ++i) {
      if (j < N && S.charAt(j) == p.charAt(i)) {
        ++j;
      } else if (S.charAt(0) == p.charAt(i)) {
        j = 1;
      } else {
        j = 0;
      }
      coins = Math.max(coins, j);
    }
    return coins;
  }

  private static boolean is_initialized = false;

  public static void run() throws IOException {
    if (is_initialized) {
      System.out.println("Error: run() must not be called twice.");
      System.exit(1);
    }
    is_initialized = true;

    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    S = reader.readLine();
    N = S.length();
    String answer = new combo().guess_sequence(N);
    if (!answer.equals(S)) {
      wrong_answer("wrong guess");
    }
    System.out.println("Accepted: " + num_moves);
  }

  private static void wrong_answer(String MSG) {
    System.out.println("Wrong Answer: " + MSG);
    System.exit(0);
  }
}
