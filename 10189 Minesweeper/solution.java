import java.io.*;

public class Main {
    static int[] dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, -1, 1};
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int x = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            st.nextToken();
            int m = (int)st.nval;
            if(n == 0 && m == 0)
                break;
            if(x >= 1)
                output.append('\n');
            output.append("Field #").append(++x).append(":\n");
            char[][] field = new char[n][m];
            for(int i = 0; i < n; ++i)
                field[i] = br.readLine().toCharArray();
            for(int i = 0; i < n; ++i) {
    	        for(int j = 0; j < m; ++j) {
    	            if(field[i][j] == '.') {
    	                field[i][j] = '0';
    	                for(int dir = 0; dir < 8; ++dir) {
    	                    int newRow = i + dRow[dir], newCol = j + dCol[dir];
    	                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && field[newRow][newCol] == '*')
    	                        ++field[i][j];
    	                }
    	            }
    	        }
    	    }
    	    for(int i = 0; i < n; ++i) {
    	        for(int j = 0; j < m; ++j)
    	            output.append(field[i][j]);
    	        output.append('\n');
    	    }
        }
        System.out.print(output);
	}
}
