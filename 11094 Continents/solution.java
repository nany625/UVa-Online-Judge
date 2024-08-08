import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int M = (int)st.nval;
            st.nextToken();
            int N = (int)st.nval;
            char[][] map = new char[M][N];
            for(int i = 0; i < M; ++i)
                map[i] = br.readLine().toCharArray();
            st.nextToken();
            int X = (int)st.nval;
            st.nextToken();
            int Y = (int)st.nval;
            char region = map[X][Y];
            dfs(map, X, M, Y, N, region);
            int max = 0;
            for(int i = 0; i < M; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(map[i][j] == region) {
                        int[] area = new int[1];
                        capture(map, i, M, j, N, region, area);
                        max = Math.max(max, area[0]);
                    }
                }
            }
            output.append(max + "\n");
    	}
        System.out.print(output);
	}
	
	static void dfs(char[][] map, int row, int rowLimit, int col, int colLimit, char region) {
        if(map[row][col] == region) {
            map[row][col] = ' ';
            if(row - 1 >= 0)
                dfs(map, row - 1, rowLimit, col, colLimit, region);
            if(col - 1 >= 0)
                dfs(map, row, rowLimit, col - 1, colLimit, region);
            else
                dfs(map, row, rowLimit, colLimit - 1, colLimit, region);
            if(row + 1 < rowLimit)
                dfs(map, row + 1, rowLimit, col, colLimit, region);
            if(col + 1 < colLimit)
                dfs(map, row, rowLimit, col + 1, colLimit, region);
            else
                dfs(map, row, rowLimit, 0, colLimit, region);
        }
    }
    
    static void capture(char[][] map, int row, int rowLimit, int col, int colLimit, char region, int[] area) {
        if(map[row][col] == region) {
            map[row][col] = ' ';
            ++area[0];
            if(row - 1 >= 0)
                capture(map, row - 1, rowLimit, col, colLimit, region, area);
            if(col - 1 >= 0)
                capture(map, row, rowLimit, col - 1, colLimit, region, area);
            else
                capture(map, row, rowLimit, colLimit - 1, colLimit, region, area);
            if(row + 1 < rowLimit)
                capture(map, row + 1, rowLimit, col, colLimit, region, area);
            if(col + 1 < colLimit)
                capture(map, row, rowLimit, col + 1, colLimit, region, area);
            else
                capture(map, row, rowLimit, 0, colLimit, region, area);
        }
    }
}
