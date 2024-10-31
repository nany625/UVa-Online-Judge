import java.io.*;

public class Main {
    static int[] dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, -1, 1};
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int m = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            String[] grid = new String[m];
            for(int i = 0; i < m; ++i) {
                st.nextToken();
			    grid[i] = st.sval;
            }
            st.nextToken();
            int k = (int)st.nval;
            while(k-- > 0) {
                st.nextToken();
                String word = st.sval;
                boolean found = false;
    			for(int row = 0; row < m && !found; ++row) {
    				for(int col = 0; col < n && !found; ++col) {
    					for(int dir = 0; dir < 8 && !found; ++dir) {
                            if(searchInDirection(grid, m, n, word, row, col, dir)) {
                                output.append(row + 1).append(' ').append(col + 1).append('\n');
                                found = true;
                            }
                        }
    				}
    			}
            }
            if(cases > 0)
			    output.append('\n');
        }
        System.out.print(output);
	}
	
	static boolean searchInDirection(String[] grid, int m, int n, String word, int row, int col, int dir) {
        for(int i = 0; i < word.length(); ++i) {
            int newRow = row + i * dRow[dir], newCol = col + i * dCol[dir];
            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || 
                Character.toUpperCase(word.charAt(i)) != Character.toUpperCase(grid[newRow].charAt(newCol))) {
                return false;
            }
        }
        return true;
    }
}
