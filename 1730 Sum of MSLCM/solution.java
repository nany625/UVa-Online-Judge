import java.io.*;

public class Main {
    static int MAX_NUM = 20000000;
    static long[] ans = new long[MAX_NUM + 1];
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
        for(int n = 2; n <= MAX_NUM; ++n) {
            for(int i = n; i <= MAX_NUM; i += n)
                ans[i] += n;
        }
        for(int n = 3; n <= MAX_NUM; ++n)
            ans[n] += ans[n - 1];
    }
}
