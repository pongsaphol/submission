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
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
        	a[i] = nextInt();
        }
        tetris t = new tetris();
        t.init(n);
        for (int i = 0; i < n; i++) {
        	t.new_figure(a[i]);
        	out.println(t.get_position() + " " + t.get_rotation());
        }
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
