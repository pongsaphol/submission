import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

class cycle_lib {

	private static final int cnt_lim = 35;
	private static int n, p, cnt;

	private static void wrong_answer(String reason) {
		System.out.println(reason);
		System.exit(0);
	}

	public static boolean jump(int x) {
		if(x < 0 || x >= n) wrong_answer("Invalid argument.");
		cnt++;
		if(cnt > cnt_lim) wrong_answer("Too many queries.");

		p = (p + x) % n;
		return (n - p) % n <= n / 2;
	}

	public static void run() throws IOException {
		InputReader inputReader = new InputReader(System.in);
		n = inputReader.readInt();
		p = inputReader.readInt();
		cnt = 0;

		cycle solver = new cycle();
		solver.escape(n);
		if(p != 0) wrong_answer("The exit was not found.");

		System.out.println("OK");
		System.err.println(cnt);
		System.out.close();
	}
}

class InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1) {
			throw new InputMismatchException();
		}
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0) {
				return -1;
			}
		}
		return buf[curChar++];
	}

	public int readInt() {
		int c = eatWhite();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9') {
				throw new InputMismatchException();
			}
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
	}

	public String readString() {
		int c = eatWhite();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	private int eatWhite() {
		int c = read();
		while (isSpaceChar(c)) {
			c = read();
		}
		return c;
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
}


public class grader {
  public static void main(String[] args) throws IOException {
    cycle_lib.run();
  }
}
