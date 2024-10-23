import java.io.*;

public class Main {
    static int[] dRow = {-1, -1}, dCol = {1, -1};
    static char[][] board = new char[100][100];
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
		        board[j] = br.readLine().toCharArray();
		    int startRow = 0, startCol = 0;
            while(board[startRow][startCol] != 'W') {
                ++startCol;
                if(startCol == N) {
                    ++startRow;
                    startCol = 0;
                }
            }
            int[][] paths = new int[startRow + 1][N];
            paths[startRow][startCol] = 1;
		    for(int j = startRow; j > 0; --j) {
                for(int k = 0; k < N; ++k) {
                    for(int l = 0; l < 2; ++l) {
                        int newRow = j + dRow[l], newCol = k + dCol[l];
                        if(newRow >= 0 && newCol >= 0 && newCol < N) {
                            if(board[newRow][newCol] == '.')
                                paths[newRow][newCol] = (paths[newRow][newCol] + paths[j][k]) % 1000007;
                            else if(board[newRow][newCol] == 'B') {
                                newRow = j + (dRow[l] << 1);
                                newCol = k + (dCol[l] << 1);
                                if(newRow >= 0 && newCol >= 0 && newCol < N && board[newRow][newCol] == '.')
                                    paths[newRow][newCol] = (paths[newRow][newCol] + paths[j][k]) % 1000007;
                            }
                        }
                    }
                }
            }
            int totalPaths = 0;
            for(int j = (startRow + startCol) & 1; j < N; j += 2)
                totalPaths += paths[0][j];
            output.append("Case ").append(i).append(": ").append(totalPaths %= 1000007).append('\n');
		}
        System.out.print(output);
	}
}
