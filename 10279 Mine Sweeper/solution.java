import java.io.*;

public class Main {
    static int[] dRow = {0, 1, 0, -1, 1, 1, -1, -1}, dCol = {1, 0, -1, 0, 1, -1, -1, 1};
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int games = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(games-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            char[][] mines = new char[n][n], touch = new char[n][n];
            for(int i = 0; i < n; ++i)
                mines[i] = br.readLine().toCharArray();
            for(int i = 0; i < n; ++i)
                touch[i] = br.readLine().toCharArray();
            boolean boom = false;
            for(int i = 0; i < n; ++i) {
    	        for(int j = 0; j < n; ++j) {
    	            if(touch[i][j] == 'x') {
    	                if(mines[i][j] == '*') {
    	                    touch[i][j] = '*';
    	                    boom = true;
    	                } else {
        	                touch[i][j] = '0';
        	                for(int dir = 0; dir < 8; ++dir) {
        	                    int newRow = i + dRow[dir], newCol = j + dCol[dir];
        	                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && mines[newRow][newCol] == '*')
        	                        ++touch[i][j];
        	                }
    	                }
    	            }
    	        }
    	    }
    	    if(boom) {
    	        for(int i = 0; i < n; ++i) {
        	        for(int j = 0; j < n; ++j) {
        	            if(mines[i][j] == '*')
        	                touch[i][j] = '*';
        	        }
    	        }
    	    }
    	    for(int i = 0; i < n; ++i) {
        	    for(int j = 0; j < n; ++j)
        	        output.append(touch[i][j]);
        	    output.append('\n');
    	    }
    	    if(games > 0)
                output.append('\n');
        }
        System.out.print(output);
	}
}
