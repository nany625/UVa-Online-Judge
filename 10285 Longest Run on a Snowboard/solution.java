import java.io.*;
import java.util.*;

public class Main {
    static int[] dRow = {1, 0, 0, -1}, dCol = {0, 1, -1, 0};
    static short[][] height = new short[100][100], memo = new short[100][100];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            output.append(st.sval).append(": ");
            st.nextToken();
            int R = (int)st.nval;
            st.nextToken();
            int C = (int)st.nval;
            for(int i = 0; i < R; ++i) {
                for(int j = 0; j < C; ++j) {
                    st.nextToken();
                    height[i][j] = (short)st.nval;
                }
            }
            for(int i = 0; i < R; ++i)
                Arrays.fill(memo[i], (short)0);
            short max = 1;
            for(int i = 0; i < R; ++i) {
                for(int j = 0; j < C; ++j) {
                    short length = dfs(i, R, j, C);
                    max = (short)Math.max(max, length);
                }
            }
            output.append(max).append('\n');
        }
        System.out.print(output);
    }
    
    static short dfs(int row, int rowLimit, int col, int colLimit) {
        if(memo[row][col] != 0)
            return memo[row][col];
        short maxLength = 1;
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i], newCol = col + dCol[i];
            if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && height[newRow][newCol] < height[row][col]) {
                short temp = (short)(1 + dfs(newRow, rowLimit, newCol, colLimit));
                maxLength = (short)Math.max(maxLength, temp);
            }
        }
        return memo[row][col] = maxLength;
    }
}
