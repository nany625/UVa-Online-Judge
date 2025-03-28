import java.io.*;

public class Main {
    static int MAXN = 999999;
    static short[] collatz = new short[MAXN + 1];
	public static void main(String[] args) throws IOException {
        collatz[1] = 1;
        for(int n = 2; n <= MAXN; ++n)
            init(n);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int min = (int)st.nval;
    	    st.nextToken();
    	    int max = (int)st.nval;
    	    output.append(min).append(' ').append(max).append(' ');
    	    if(min > max) {
    	        int temp = min;
    	        min = max;
    	        max = temp;
    	    }
    	    short maxLen = collatz[min];
    	    for(int i = min + 1; i <= max; ++i)
                maxLen = (short)Math.max(maxLen, collatz[i]);
            output.append(maxLen).append('\n');
		}
		System.out.print(output);
	}
	
	static void init(int n) {
        collatz[n] = (short)1;
        long temp = n;
        while(temp != 1) {
            if(temp < n) {
                collatz[n] += collatz[(int)temp] - 1;
                return;
            }
            temp = (temp & 1) == 1 ? 3 * temp + 1 : temp >> 1;
            ++collatz[n];
        }
    }
}
