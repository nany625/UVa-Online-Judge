import java.io.*;

public class Main {
    static int[] dRow = {1, 0, 0, -1}, dCol = {0, 1, -1, 0};
    static char[][] map = new char[20][20];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int M = (int)st.nval;
            st.nextToken();
            int N = (int)st.nval;
            for(int i = 0; i < M; ++i)
                map[i] = br.readLine().toCharArray();
            st.nextToken();
            int X = (int)st.nval;
            st.nextToken();
            int Y = (int)st.nval;
            char region = map[X][Y];
            dfs(X, M, Y, N, region);
            int max = 0;
            for(int i = 0; i < M; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(map[i][j] == region) {
                        int[] area = new int[1];
                        capture(i, M, j, N, region, area);
                        max = Math.max(max, area[0]);
                    }
                }
            }
            output.append(max).append('\n');
    	}
        System.out.print(output);
	}
	
	static void dfs(int row, int rowLimit, int col, int colLimit, char region) {
        if(map[row][col] == region) {
            map[row][col] = ' ';
            for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
                if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                    dfs(newRow, rowLimit, newCol, colLimit, region);
                else if(newCol == -1)
                    dfs(newRow, rowLimit, colLimit - 1, colLimit, region);
                else if(newCol == colLimit)
                    dfs(newRow, rowLimit, 0, colLimit, region);
            }
        }
    }
    
    static void capture(int row, int rowLimit, int col, int colLimit, char region, int[] area) {
        if(map[row][col] == region) {
            map[row][col] = ' ';
            ++area[0];
            for(int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit)
                    capture(newRow, rowLimit, newCol, colLimit, region, area);
                else if(newCol == -1)
                    capture(newRow, rowLimit, colLimit - 1, colLimit, region, area);
                else if(newCol == colLimit)
                    capture(newRow, rowLimit, 0, colLimit, region, area);
            }
        }
    }
}
