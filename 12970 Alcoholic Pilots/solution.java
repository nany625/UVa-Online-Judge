import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    long v1 = (long)st.nval;
		    st.nextToken();
		    long d1 = (long)st.nval;
		    st.nextToken();
		    long v2 = (long)st.nval;
		    st.nextToken();
		    long d2 = (long)st.nval;
		    if(v1 == 0 && d1 == 0 && v2 == 0 && d2 == 0)
		        break;
		    output.append("Case #" + (++cases) + ": " + (d1 * v2 < d2 * v1 ? "You owe me a beer!" : "No beer for the captain.") + "\nAvg. arrival time: ");
		    long numerator = d1 * v2 + v1 * d2, denominator = 2 * v1 * v2;
            long temp = GCD(numerator, denominator);
            numerator /= temp;
            denominator /= temp;
            if(denominator > 1)
    			output.append(numerator + "/" + denominator + "\n");
    		else
    			output.append(numerator / denominator + "\n");
		}
		System.out.print(output);
	}
	
	static long GCD(long i, long j) {
        return j == 0 ? i : GCD(j, i % j);
    }
}
