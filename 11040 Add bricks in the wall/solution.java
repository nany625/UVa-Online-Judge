import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    int[][] brick = new int[9][9];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
    	            brick[i][j] = (brick[i - 2][j - 1] - brick[i][j - 1] - brick[i][j + 1]) >> 1;
    	    }
    	    for(int i = 0; i < 9; ++i) {
    	        for(int j = 0; j < i; ++j)
    	            output.append((i & 1) == 1 ? brick[i + 1][j] + brick[i + 1][j + 1] : brick[i][j]).append(' ');
    	        output.append((i & 1) == 1 ? brick[i + 1][i] + brick[i + 1][i + 1] : brick[i][i]).append('\n');
    	    }
		}
		System.out.print(output);
	}
}
