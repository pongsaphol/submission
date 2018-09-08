public class combo {
  String guess_sequence(int N) {
    String p = "";
    for (int i = 0; i < 4 * N; ++i) {
      p += 'A';
    }
    int coins = combo_lib.press(p);
    String S = "";
    for (int i = 0; i < N; ++i) {
      S += 'A';
    }
    return S;
  }
}
