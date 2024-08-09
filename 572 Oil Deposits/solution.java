import java.io.*;

public class Main {
    static int[] dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, 1, -1};
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        int m, n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (m = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            char[][] grid = new char[m][n];
            for(int i = 0; i < m; ++i)
                grid[i] = br.readLine().toCharArray();
            int count = 0;
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(grid[i][j] == '@') {
                        ++count;
                        dfs(grid, i, m, j, n);
                    }
                }
            }
            output.append(count + "\n");
    	}
        System.out.print(output);
	}
	
	static void dfs(char[][] grid, int row, int rowLimit, int col, int colLimit) {
        if(grid[row][col] == '@') {
            grid[row][col] = '*';
            for(int i = 0; i < 8; ++i) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                    dfs(grid, newRow, rowLimit, newCol, colLimit);
            }
        }
    }
}
