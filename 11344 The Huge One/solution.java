import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
	    st.nextToken();
	    int N = (int)st.nval;
	    StringBuilder output = new StringBuilder();
	    while(N-- > 0) {
    	    String M = br.readLine();
    	    st.nextToken();
    	    int len = M.length(), S = (int)st.nval;
    	    boolean wonderful = true;
		    while(S-- > 0) {
    	        st.nextToken();
                short divisor = (short)st.nval;
                if(wonderful) {
                    int dividend = 0;
                    for(int i = 0; i < len; ++i)
                        dividend = (10 * dividend + M.charAt(i) - '0') % divisor;
                    wonderful = dividend == 0;
                }	
            }
    	    output.append(M).append(wonderful ? " - Wonderful.\n" : " - Simple.\n");
    	}
	    System.out.print(output);
	}
}
