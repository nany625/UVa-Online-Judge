import java.io.*;

public class Main {
    static int[] dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, -1, 1};
	public static void main(String[] args) {
	    try {
    	    StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int cases = (int)st.nval;
            boolean blankLine = false;
            while(cases-- > 0) {
                if(blankLine)
				    System.out.println();
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
				    int wordLen = word.length();
                    boolean found = false;
    				for(int row = 0; row < m && !found; ++row) {
    					for(int col = 0; col < n && !found; ++col) {
    						for(int dir = 0; dir < 8 && !found; ++dir) {
                                if(searchInDirection(grid, m, n, word, wordLen, row, col, dir)) {
                                    System.out.println((row + 1) + " " + (col + 1));
                                    found = true;
                                }
                            }
    					}
    				}
                    blankLine = true;
                }
            }
	    } catch(IOException e) {}
	}
	
	static boolean searchInDirection(String[] grid, int m, int n, String word, int wordLen, int row, int col, int dir) {
        for(int i = 0; i < wordLen; ++i) {
            int newRow = row + i * dRow[dir], newCol = col + i * dCol[dir];
            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || 
                Character.toUpperCase(word.charAt(i)) != Character.toUpperCase(grid[newRow].charAt(newCol))) {
                return false;
            }
        }
        return true;
    }
}
