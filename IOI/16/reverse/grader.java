import java.io.*;
import java.util.StringTokenizer;

public class grader {

    public static void main(String[] args) throws IOException {
        new grader().run();
    }
    
    void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        int n = nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
        	a[i] = nextLong();
        }
        long[] ans = new reverse().reverse(a);

        
        for (int i = 0; i < n; i++) {
        	out.print(ans[i] + " ");
        }
        out.println();
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
