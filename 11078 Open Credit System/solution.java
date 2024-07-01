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
    		    int senior = (int)st.nval;
    		    st.nextToken();
    		    int junior = (int)st.nval;
    		    int maxScore = Math.max(senior, junior), maxDist = senior - junior;
    		    while(n-- > 2) {
    		        st.nextToken();
    		        junior = (int)st.nval;
    		        maxDist = Math.max(maxDist, maxScore - junior);
    		        maxScore = Math.max(maxScore, junior);
    		    }
        		System.out.println(maxDist);
	        }
	    } catch(IOException e) {}
	}
}
