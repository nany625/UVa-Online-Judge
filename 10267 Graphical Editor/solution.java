import java.io.*;
import java.util.*;

public class Main {
    static char[][] table = new char[250][250];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String command;
	    char C;
		int M = 0, N = 0, X, X1, X2, Y, Y1, Y2;
		StringBuilder output = new StringBuilder();
    	while((command = br.readLine()) != null && command.charAt(0) != 'X') {
    	    String[] tokens = command.split("\\s+");
    	    if(command.charAt(0) == 'I') {
    	        M = Integer.parseInt(tokens[1]);
    	        N = Integer.parseInt(tokens[2]);
    	        fill(0, N - 1, 0, M - 1, 'O');
    	    } else if(command.charAt(0) == 'C')
    		    fill(0, N - 1, 0, M - 1, 'O');
    		else if(command.charAt(0) == 'L') {
    	        X = Integer.parseInt(tokens[1]);
    	        Y = Integer.parseInt(tokens[2]);
    	        C = tokens[3].charAt(0);
    			table[Y - 1][X - 1] = C;
    		} else if(command.charAt(0) == 'V') {
    		    X = Integer.parseInt(tokens[1]);
    	        Y1 = Integer.parseInt(tokens[2]);
    	        Y2 = Integer.parseInt(tokens[3]);
    	        C = tokens[4].charAt(0);
    			if(Y1 > Y2) {
    			    int temp = Y1;
    			    Y1 = Y2;
    			    Y2 = temp;
    			}
    			for(int i = Y1 - 1; i <= Y2 - 1; ++i)
    				table[i][X - 1] = C;
    		} else if(command.charAt(0) == 'H') {
    		    X1 = Integer.parseInt(tokens[1]);
    	        X2 = Integer.parseInt(tokens[2]);
    	        Y = Integer.parseInt(tokens[3]);
    	        C = tokens[4].charAt(0);
    			if(X1 > X2) {
    			    int temp = X1;
    			    X1 = X2;
    			    X2 = temp;
    			}
    			Arrays.fill(table[Y - 1], X1 - 1, X2, C);
    		} else if(command.charAt(0) == 'K') {
    		    X1 = Integer.parseInt(tokens[1]);
    	        Y1 = Integer.parseInt(tokens[2]);
    	        X2 = Integer.parseInt(tokens[3]);
    	        Y2 = Integer.parseInt(tokens[4]);
    	        C = tokens[5].charAt(0);
    			fill(Y1 - 1, Y2 - 1, X1 - 1, X2 - 1, C);
    		} else if(command.charAt(0) == 'F') {
    	        X = Integer.parseInt(tokens[1]);
    	        Y = Integer.parseInt(tokens[2]);
    	        C = tokens[3].charAt(0);
    			dfs(Y - 1, N, X - 1, M, table[Y - 1][X - 1], C);
    		} else if(command.charAt(0) == 'S') {
    			output.append(tokens[1] + "\n");
    			for(int i = 0; i < N; ++i)
    			    output.append(new String(table[i], 0, M) + "\n");
    		}
    	}
	    System.out.print(output);
	}
	
	static void fill(int row1, int row2, int col1, int col2, char C) {
        for(int i = row1; i <= row2; ++i)
            Arrays.fill(table[i], col1, col2 + 1, C);
    }
    
    static void dfs(int row, int rowLimit, int col, int colLimit, char R, char C) {
        if(C != R) {
            table[row][col] = C;
            if(row + 1 < rowLimit && table[row + 1][col] == R)
                dfs(row + 1, rowLimit, col, colLimit, R, C);
            if(col + 1 < colLimit && table[row][col + 1] == R)
                dfs(row, rowLimit, col + 1, colLimit, R, C);
            if(row - 1 >= 0 && table[row - 1][col] == R)
                dfs(row - 1, rowLimit, col, colLimit, R, C);
            if(col - 1 >= 0 && table[row][col - 1] == R)
                dfs(row, rowLimit, col - 1, colLimit, R, C);
        }
    }
}
