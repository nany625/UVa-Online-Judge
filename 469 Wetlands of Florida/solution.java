import java.io.*;
import java.util.*;

public class Main {
    static int[] dRow = {1, 1, 1, 0, 0, -1, -1, -1}, dCol = {1, 0, -1, 1, -1, 1, 0, -1};
    static char[][] grid = new char[99][99];
    static boolean[][] visited = new boolean[99][99];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval, n = 0;
        br.readLine();
        String line;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    while((line = br.readLine()) != null && !line.isEmpty()) {
		        if(Character.isUpperCase(line.charAt(0)))
		            grid[n++] = line.toCharArray();
		        else {
		            String[] tokens = line.split("\\s+");
		            int i = Integer.parseInt(tokens[0]) - 1, j = Integer.parseInt(tokens[1]) - 1;
		            int m = grid[0].length;
		            int[] area = new int[1];
		            for(boolean[] b : visited)
		                Arrays.fill(b, false);
		            dfs(i, n, j, m, area);
		            output.append(area[0]).append('\n');
		        }
		    }
		    n = 0;
		    if(T > 0)
		        output.append('\n');
		}
        System.out.print(output);
	}
	
	static void dfs(int row, int rowLimit, int col, int colLimit, int[] area) {
        ++area[0];
        visited[row][col] = true;
        for(int i = 0; i < 8; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && !visited[newRow][newCol] && grid[newRow][newCol] == grid[row][col])
                dfs(newRow, rowLimit, newCol, colLimit, area);
        }
    }
}
