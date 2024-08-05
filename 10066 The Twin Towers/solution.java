import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int twinTowers = 0, N1, N2;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N1 = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (N2 = (int)st.nval) != 0) {
    	    int[] tiles1 = new int[N1], tiles2 = new int[N2];
    	    for(int i = 0; i < N1; ++i) {
    	        st.nextToken();
    	        tiles1[i] = (int)st.nval;
    	    }
    	    for(int i = 0; i < N2; ++i) {
    	        st.nextToken();
    	        tiles2[i] = (int)st.nval;
    	    }
    	    int[][] L = new int[N1 + 1][N2 + 1];
    	    for(int i = 1; i <= N1; ++i) {
    	        for(int j = 1; j <= N2; ++j) {
    	            if(tiles1[i - 1] == tiles2[j - 1])
    	                L[i][j] = L[i - 1][j - 1] + 1;
    	            else
    	                L[i][j] = Math.max(L[i - 1][j], L[i][j - 1]);
    	        }
    	    }
    	    output.append("Twin Towers #" + (++twinTowers) + "\nNumber of Tiles : " + L[N1][N2] + "\n\n");
    	}
        System.out.print(output);
	}
}
