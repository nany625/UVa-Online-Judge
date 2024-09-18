import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
	        int N = (int)st.nval;
	        int[][] factors = new int[N - 1][2];
		    long[][] C = new long[N][N + 1];
		    st.nextToken();
		    C[0][0] = (long)st.nval * (-1);
		    C[0][1] = 1;
    		for(int i = 0; i < N - 1; ++i) {
    		    st.nextToken();
    			factors[i][0] = (int)st.nval * (-1);
    			factors[i][1] = 1;
    			for(int j = 0; j < i + 3; ++j)
    				C[i + 1][j] = 0;
    			for(int j = 0; j < i + 2; ++j) {
    				for(int k = 0; k < 2; ++k)
    					C[i + 1][j + k] += C[i][j] * factors[i][k];
    			}
    		}
    		if(N > 1)
    			output.append("x^").append(N);
    		else
    			output.append('x');
    		for(int i = N - 1; i >= 0; --i) {
    			if(C[N - 1][i] != 0) {
    				if(C[N - 1][i] > 0)
    					output.append(" + ");
    				else
    					output.append(" - ");
    				if(i > 1) {
    					if(Math.abs(C[N - 1][i]) > 1)
    						output.append(Math.abs(C[N - 1][i])).append("x^").append(i);
    					else
    						output.append("x^").append(i);
    				} else if(i == 1) {
    					if(Math.abs(C[N - 1][i]) > 1)
    						output.append(Math.abs(C[N - 1][i])).append('x');
    					else
    						output.append('x');
    				} else
    					output.append(Math.abs(C[N - 1][i]));
    			}
    		}
    		if(C[N - 1][0] == 0)
    			output.append(" + 0");
    		output.append(" = 0\n");
	    }
	    System.out.print(output);
	}
}
