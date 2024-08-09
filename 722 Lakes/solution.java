import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int M = (int)st.nval;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while(M-- > 0) {
            if(!firstCase)
                output.append("\n");
            st.nextToken();
            int i = (int)st.nval - 1;
            st.nextToken();
            int j = (int)st.nval - 1;
            ArrayList<char[]> grid = new ArrayList<>();
            String line;
            while((line = br.readLine()) != null && !line.isEmpty())
                grid.add(line.toCharArray());
            int rows = grid.size(), cols = grid.get(0).length;
            int[] area = new int[1];
            dfs(grid, i, rows, j, cols, area);
            output.append(area[0] + "\n");
            firstCase = false;
        }
        System.out.print(output);
	}
	
	static void dfs(ArrayList<char[]> grid, int row, int rowLimit, int col, int colLimit, int[] area) {
        if(grid.get(row)[col] == '0') {
            grid.get(row)[col] = '1';
            ++area[0];
            if(row - 1 >= 0)
                dfs(grid, row - 1, rowLimit, col, colLimit, area);
            if(col - 1 >= 0)
                dfs(grid, row, rowLimit, col - 1, colLimit, area);
            if(row + 1 < rowLimit)
                dfs(grid, row + 1, rowLimit, col, colLimit, area);
            if(col + 1 < colLimit)
                dfs(grid, row, rowLimit, col + 1, colLimit, area);
        }
    }
}
