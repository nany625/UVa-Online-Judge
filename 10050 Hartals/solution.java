import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int T = (int)st.nval;
	    StringBuilder output = new StringBuilder();
	    while(T-- > 0) {
	        st.nextToken();
    	    short N = (short)st.nval;
    	    st.nextToken();
    	    int P = (int)st.nval;
    	    short[] h = new short[P];
    	    for(int i = 0; i < P; ++i) {
    	        st.nextToken();
    	        h[i] = (short)st.nval;
    	    }
    	    int hartals = 0;
    	    do {
    	        if((N - 6) % 7 != 0 && N % 7 != 0) {
    	            for(int i = 0; i < P; ++i) {
    	                if(N % h[i] == 0) {
    	                    ++hartals;
    	                    break;
    	                }
    	            }
    	        }
    	    } while(N-- > 0);
    	    output.append(hartals + "\n");
    	}
        System.out.print(output);
	}
}
