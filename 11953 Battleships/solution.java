import java.io.*;

public class Main {
    static int[] dRow = {1, -1, 0, 0}, dCol = {0, 0, 1, -1};
    static char[][] grid = new char[100][100];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
		    int N = (int)st.nval;
		    for(int j = 0; j < N; ++j)
		        grid[j] = br.readLine().toCharArray();
		    int count = 0;
            for(int j = 0; j < N; ++j) {
                for(int k = 0; k < N; ++k) {
                    if(grid[j][k] == 'x') {
                        ++count;
                        dfs(j, k, N);
                    }
                }
            }
            output.append("Case ").append(i).append(": ").append(count).append('\n');
		}
		System.out.print(output);
	}
	
	static void dfs(int row, int col, int N) {
        grid[row][col] = '.';
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < N && newCol >= 0 && newCol < N && (grid[newRow][newCol] == 'x' || grid[newRow][newCol] == '@'))
                dfs(newRow, newCol, N);
        }
    }
}
