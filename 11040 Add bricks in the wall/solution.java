import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    int[][] brick = new int[9][9];
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(N-- > 0) {
		    for(int i = 0; i < 9; i += 2) {
    	        for(int j = 0; j <= i; j += 2) {
    	            st.nextToken();
    	            brick[i][j] = (int)st.nval;
    	        }
    	    }
    	    for(int i = 2; i < 9; i += 2) {
    	        for(int j = 1; j < i; j += 2)
    	            brick[i][j] = (brick[i - 2][j - 1] - brick[i][j - 1] - brick[i][j + 1]) / 2;
    	    }
    	    for(int i = 0; i < 9; ++i) {
    	        for(int j = 0; j <= i; ++j) {
    	            if(j > 0)
    	                output.append(" ");
    	            output.append(i % 2 == 0 ? brick[i][j] : brick[i + 1][j] + brick[i + 1][j + 1]);
    	        }
    	        output.append("\n");
    	    }
		}
		System.out.print(output);
	}
}
