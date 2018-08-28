import java.io.EOFException;
import java.io.IOException;

public class grader {
	public static void main(String[] args) throws IOException {
		int N = readInt();
		int C = readInt();
		int Q = readInt();
		int[] T = new int[C];
		int[] X = new int[C];
		int[] Y = new int[C];
		for (int i = 0; i < C; ++i) {
			T[i] = readInt();
			X[i] = readInt();
			Y[i] = readInt();
		}
		int[] W = new int[Q];
		int[] P = new int[Q];
		for (int j = 0; j < Q; ++j) {
			W[j] = readInt();
			P[j] = readInt();
		}
		int[] answer = new collapse().simulateCollapse(N, T, X, Y, W, P);
		for (int j = 0; j < answer.length; ++j) {
			System.out.println(answer[j]);
		}
	}

	private static int readInt() throws IOException {
		int x = 0, c;
		for (; ; ) {
			c = System.in.read();
			if ('0' <= c && c <= '9') break;
			if (c == -1) throw new EOFException();
			if (c == '-') return -readInt();
		}
		for (; ; ) {
			x = x * 10 + (c - '0');
			c = System.in.read();
			if (!('0' <= c && c <= '9')) return x;
		}
	}
}
