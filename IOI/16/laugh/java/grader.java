import java.io.*;
import java.util.StringTokenizer;

public class grader {

    public static void main(String[] args) throws IOException {
        new grader().run();
    }
    
    void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        String s = next();
        int ans = new laugh().longest_laugh(s);
 
        out.println(ans);
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
