import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.InputMismatchException;


public class grader {
	
	private static InputReader inputReader;
	private static transfer solver_prog;
	
	private static String run_scenario() {
		int c = inputReader.readInt();
		if (c < -1)
			return "invalid corruption index";
		String source_str = inputReader.readString();
		final int N = source_str.length();
		final int max_attachment_size = 2*N;
		int[] source = new int[source_str.length()];
		for (int i = 0; i < N; i++)
			source[i] = (int)(source_str.charAt(i)-'0');
		
		int[] attachment = solver_prog.get_attachment(source);
		if (attachment.length > max_attachment_size)
			return "attachment too large";
		for (int x : attachment)
			if (x != 0 && x != 1)
				return "invalid attachment integer value";
		
		int[] data = new int[source.length+attachment.length];
		System.arraycopy(source, 0, data, 0, source.length);
		System.arraycopy(attachment, 0, data, source.length, attachment.length);
		
		if (c >= data.length)
			return "invalid corruption index";
		
		if (c >= 0)
			data[c] = 1-data[c];

		int[] result_source = solver_prog.retrieve(data);
		
		if (!Arrays.equals(source, result_source))
			return "wrong source retrieval";

		return "OK K="+attachment.length;
	}
	
	public static void main(String[] args) {
		inputReader = new InputReader(System.in);
		solver_prog = new transfer();
		int T = inputReader.readInt();
		for (int scenario = 1; scenario <= T; scenario++) {
			String result = run_scenario();
			System.out.println("scenario #" + scenario + ": " + result);
		}
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
