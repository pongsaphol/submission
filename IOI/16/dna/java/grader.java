import java.io.*;
import java.util.StringTokenizer;

public class grader {

	private static int tests = 0;
	private static String s;

	public static boolean make_test(String p) {
		tests++;
		for (int i = 0; i < p.length(); i++) {
			if (p.charAt(i) != '0' && p.charAt(i) != '1') {
				return false;
			}
		}
		String ss = p + "#" + s;
		int[] pr = new int[ss.length() + 1];
		pr[0] = -1;
		boolean answer = false;
		for (int i = 1; i <= ss.length(); i++) {
			int k = pr[i - 1];
			while (k >= 0 && ss.charAt(k) != ss.charAt(i - 1))
				k = pr[k];
			pr[i] = k + 1;
			if (pr[i] == p.length()) {
				answer = true;
				break;
			}
		} 
		return answer;
	}

    public static void main(String[] args) throws IOException {
        new grader().run();
    }
    
    void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);

        s = next();
        int t = nextInt();
        String answer = new dna().analyse(s.length(), t);
            
        out.println(tests);
        out.println(answer);
        out.close();
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

    String next() {
        try {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

}
