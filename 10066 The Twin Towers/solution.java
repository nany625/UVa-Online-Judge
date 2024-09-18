import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
    	    int[] L = new int[N2 + 1];
    	    for(int i = 0; i < N1; ++i) {
    	        int prev = 0;
    	        for(int j = 1; j <= N2; ++j) {
    	            int temp = L[j];
    	            if(tiles1[i] == tiles2[j - 1])
    	                L[j] = prev + 1;
    	            else
    	                L[j] = Math.max(L[j], L[j - 1]);
    	            prev = temp;
    	        }
    	    }
    	    output.append("Twin Towers #").append(++twinTowers).append("\nNumber of Tiles : ").append(L[N2]).append("\n\n");
    	}
        System.out.print(output);
	}
}
