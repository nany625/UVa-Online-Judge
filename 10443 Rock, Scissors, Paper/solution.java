import java.io.*;

public class Main {
    static int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(t-- > 0) {
		    if(!firstCase)
			    output.append('\n');
			st.nextToken();
    		int r = (int)st.nval;
    		st.nextToken();
    		int c = (int)st.nval;
    		st.nextToken();
    		int n = (int)st.nval;
    		char[][] grid0 = new char[r][c], grid1 = new char[r][c];
    		for(int i = 0; i < r; ++i)
    		    grid0[i] = br.readLine().toCharArray();
    		for(int i = 1; i <= n; ++i) {
    			for(int j = 0; j < r; ++j) {
    				for(int k = 0; k < c; ++k) {
    					if((i & 1) == 1)
    						update(grid0, grid1, j, k, r, c);
    					else
    						update(grid1, grid0, j, k, r, c);
    				}
    			}
    		}
    		for(int i = 0; i < r; ++i)
    		    output.append((n & 1) == 1 ? new String(grid1[i]) : new String(grid0[i])).append('\n');
        	firstCase = false;
		}
		System.out.print(output);
	}
	
	static void update(char[][] today, char[][] tomorrow, int i, int j, int r, int c) {
    	char curr = tomorrow[i][j] = today[i][j], winner = (curr == 'R') ? 'S' : (curr == 'S') ? 'P' : 'R', loser = (curr == 'R') ? 'P' : (curr == 'S') ? 'R' : 'S';
        for(int[] k : directions) {
        	int ni = i + k[0], nj = j + k[1];
        	if(ni >= 0 && ni < r && nj >= 0 && nj < c) {
        		if(today[ni][nj] == winner)
        			tomorrow[ni][nj] = curr;
        		else if(today[ni][nj] == loser)
        			tomorrow[i][j] = loser;
        	}
        }
    }
}
