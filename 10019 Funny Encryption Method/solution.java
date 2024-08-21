import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int T = (int)st.nval;
	    StringBuilder output = new StringBuilder();
	    while(T-- > 0) {
	        st.nextToken();
	        int N = (int)st.nval;
	        int temp = N, count = 0;
	        while(temp > 0) {
    	        count += temp % 2;
    	        temp /= 2;
    	    }
    	    output.append(count).append(' ');
    	    count = 0;
    	    while(N > 0) {
    	        temp = N % 10;
    	        while(temp > 0) {
        	        count += temp % 2;
        	        temp /= 2;
        	    }
        	    N /= 10;
    	    }
    	    output.append(count).append('\n');
	    }
        System.out.print(output);
	}
}
