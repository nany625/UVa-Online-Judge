import java.io.*;

public class Main {
    static int MAXN = 20000000;
    static long[] ans = new long[MAXN + 1];
	public static void main(String[] args) throws IOException {
	    init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
            output.append(ans[N] + N - 1).append('\n');
		System.out.print(output);
	}
	
	static void init() {
        for(int n = 2; n <= MAXN; ++n) {
            for(int i = n; i <= MAXN; i += n)
                ans[i] += n;
        }
        for(int n = 3; n <= MAXN; ++n)
            ans[n] += ans[n - 1];
    }
}
