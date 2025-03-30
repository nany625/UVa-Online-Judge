import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
        long v1;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (v1 = (long)st.nval) != 0) {
		    st.nextToken();
		    long d1 = (long)st.nval;
		    st.nextToken();
		    long v2 = (long)st.nval;
		    st.nextToken();
		    long d2 = (long)st.nval;
		    output.append("Case #").append(++cases).append(": ").append(d1 * v2 < d2 * v1 ? "You owe me a beer!\nAvg. arrival time: " : "No beer for the captain.\nAvg. arrival time: ");
		    long numerator = d1 * v2 + v1 * d2, denominator = v1 * v2 << 1;
            long temp = GCD(numerator, denominator);
            numerator /= temp;
            denominator /= temp;
            if(denominator > 1)
    			output.append(numerator).append('/').append(denominator).append('\n');
    		else
    			output.append(numerator / denominator).append('\n');
		}
		System.out.print(output);
	}
	
	static long GCD(long i, long j) {
        return j == 0 ? i : GCD(j, i % j);
    }
}
