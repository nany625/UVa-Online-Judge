import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	        StreamTokenizer st = new StreamTokenizer(br);
	        st.nextToken();
	        int T = (int)st.nval;
	        for(int i = 1; i <= T; ++i) {
    			System.out.println("Case #" + i);
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
    				if(operation.equals("row")) {	
    				    st.nextToken();
    					int a = (int)st.nval - 1;
    					st.nextToken();
    					int b = (int)st.nval - 1;
    					char[] temp = matrix[a];
                        matrix[a] = matrix[b];
                        matrix[b] = temp;
    				} else if(operation.equals("col")) {
    					st.nextToken();
    					int a = (int)st.nval - 1;
    					st.nextToken();
    					int b = (int)st.nval - 1;
    					for(int j = 0; j < N; ++j) {
                            char temp = matrix[j][a];
                            matrix[j][a] = matrix[j][b];
                            matrix[j][b] = temp;
                        }
    				} else if(operation.equals("inc")) {
    					for(int j = 0; j < N; ++j) {
                            for(int k = 0; k < N; ++k)
                                matrix[j][k] = (char)((matrix[j][k] - '0' + 1) % 10 + '0');
                        }
    				} else if(operation.equals("dec")) {
    					for(int j = 0; j < N; ++j) {
                            for(int k = 0; k < N; ++k)
                                matrix[j][k] = (char)((matrix[j][k] - '0' + 9) % 10 + '0');
                        }
    				} else if(operation.equals("transpose")) {
    					for(int j = 0; j < N; ++j) {
                            for(int k = 1; k < N - j; ++k) {
                                char temp = matrix[j][j + k];
                                matrix[j][j + k] = matrix[j + k][j];
                                matrix[j + k][j] = temp;
                            }
                        }
    				}
    			}
    			for(int j = 0; j < N; ++j)
    				System.out.println(matrix[j]);
    			System.out.println();
    		}
	    } catch(IOException e) {}
	}
}
