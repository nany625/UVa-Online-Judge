import java.io.*;

public class Main {
    static int MAX_NUM = 1000000;
	static long[] ans = new long[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    for(int i = 4; i <= MAX_NUM; ++i) {
            long temp = (i >> 1) - 1;
            ans[i] = ans[i - 1] + (1 + temp) * temp - temp * ((i + 1) & 1);
        }
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) >= 3)
    	    output.append(ans[n]).append('\n');
        System.out.print(output);
	}
}
