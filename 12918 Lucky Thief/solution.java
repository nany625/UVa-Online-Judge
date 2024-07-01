import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int T = (int)st.nval;
    		while(T-- > 0) {
    		    st.nextToken();
                int n = (int)st.nval;
                st.nextToken();
                int m = (int)st.nval;
			    System.out.println((long)(2 * m - n - 1) * n / 2);
    		}
        } catch(IOException e) {};
	}
}
