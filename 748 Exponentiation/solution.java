import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    double R = st.nval;
    	    st.nextToken();
    	    int n = (int)st.nval;
    	    BigDecimal ans = BigDecimal.ONE;
    		while(n-- > 0)
    			ans = ans.multiply(new BigDecimal("" + R));
    		StringBuilder sb = new StringBuilder(ans.toPlainString());
    		int i = 0;
    		while(sb.charAt(i) == '0')
    			sb.delete(i, i + 1);
    		while(sb.charAt(sb.length() - 1) == '0')
    			sb.delete(sb.length() - 1, sb.length());
    		if(sb.charAt(sb.length() - 1) == '.')
    			sb.delete(sb.length() - 1, sb.length());
    		output.append(sb).append('\n');
        }
	    System.out.print(output);
	}
}
