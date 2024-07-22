import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
			output.append("Case #" + i + "\n");
			st.nextToken();
            int N = (int)st.nval;
			char[][] matrix = new char[N][N];
			for(int j = 0; j < N; ++j)
				matrix[j] = br.readLine().toCharArray();
			st.nextToken();
            int M = (int)st.nval;
			while(M-- > 0) {
			    st.nextToken();
				String operation = st.sval;
				switch(operation.charAt(0)) {
    				case 'r': {
    				    st.nextToken();
    					int a = (int)st.nval - 1;
    					st.nextToken();
    					int b = (int)st.nval - 1;
    					char[] temp = matrix[a];
                        matrix[a] = matrix[b];
                        matrix[b] = temp;
                        break;
    				}
    				case 'c': {
    					st.nextToken();
    					int a = (int)st.nval - 1;
    					st.nextToken();
    					int b = (int)st.nval - 1;
    					for(int j = 0; j < N; ++j) {
                            char temp = matrix[j][a];
                            matrix[j][a] = matrix[j][b];
                            matrix[j][b] = temp;
                        }
                        break;
        			}
        			case 'i': {
        				for(int j = 0; j < N; ++j) {
                            for(int k = 0; k < N; ++k)
                                matrix[j][k] = (char)((matrix[j][k] - '0' + 1) % 10 + '0');
                        }
                        break;
        			}
        			case 'd': {
        				for(int j = 0; j < N; ++j) {
                            for(int k = 0; k < N; ++k)
                                matrix[j][k] = (char)((matrix[j][k] - '0' + 9) % 10 + '0');
                        }
                        break;
        			}
        			case 't': {
        				for(int j = 0; j < N; ++j) {
                            for(int k = 1; k < N - j; ++k) {
                                char temp = matrix[j][j + k];
                                matrix[j][j + k] = matrix[j + k][j];
                                matrix[j + k][j] = temp;
                            }
                        }
        			}
				}
    		}
    		for(int j = 0; j < N; ++j)
    			output.append(new String(matrix[j]) + "\n");
    		output.append("\n");
    	}
	    System.out.print(output);
	}
}
