import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
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
    		output.append(maxDist).append('\n');
	    }
	    System.out.print(output);
	}
}
