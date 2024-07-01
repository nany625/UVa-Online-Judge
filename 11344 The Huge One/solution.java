import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	        StreamTokenizer st = new StreamTokenizer(br);
	        st.nextToken();
	        int N = (int)st.nval;
	        while(N-- > 0) {
    		    String M = br.readLine();
    		    st.nextToken();
    		    int len = M.length(), S = (int)st.nval;
    		    boolean wonderful = true;
    		    while(S-- > 0) {
    		        st.nextToken();
                    short divisor = (short)st.nval;
                    if(wonderful) {
                        int remainder = 0;
                        for(int i = 0; i < len; ++i) {
                            int dividend = 10 * remainder + M.charAt(i) - '0';
                            remainder = dividend % divisor;
                        }
                        if(remainder != 0)
                            wonderful = false;
                    }	
                }
    		    System.out.println(M + (wonderful ? " - Wonderful." : " - Simple."));
    		}
	    } catch(IOException e) {}
	}
}
