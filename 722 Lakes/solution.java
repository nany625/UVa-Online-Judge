import java.io.*;

public class Main {
    static int[] dRow = {1, 0, 0, -1}, dCol = {0, 1, -1, 0};
    static char[][] grid = new char[99][];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int M = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(M-- > 0) {
            st.nextToken();
            int i = (int)st.nval - 1;
            st.nextToken();
            int j = (int)st.nval - 1;
            String line;
            int rows = 0;
            while((line = br.readLine()) != null && !line.isEmpty())
                grid[rows++] = line.toCharArray();
            int[] area = new int[1];
            dfs(i, rows, j, grid[0].length, area);
            output.append(area[0]).append('\n');
            if(M > 0)
                output.append('\n');
        }
        System.out.print(output);
	}
	
	static void dfs(int row, int rowLimit, int col, int colLimit, int[] area) {
        if(grid[row][col] == '0') {
            grid[row][col] = '1';
            ++area[0];
            for(int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                    dfs(newRow, rowLimit, newCol, colLimit, area);
            }
        }
    }
}
