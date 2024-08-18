import java.io.*;
import java.util.*;

public class Main {
    static int[] dRow = {1, 0, 0, -1}, dCol = {0, 1, -1, 0};
    static char[][] table = new char[250][250];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String command;
		int M = 0, N = 0, X, X1, X2, Y, Y1, Y2;
		StringBuilder output = new StringBuilder();
    	while((command = br.readLine()) != null && command.charAt(0) != 'X') {
    	    String[] tokens = command.split("\\s+");
    	    switch(command.charAt(0)) {
    	        case 'I':
        	        M = Integer.parseInt(tokens[1]);
        	        N = Integer.parseInt(tokens[2]);
        	        fill(0, N - 1, 0, M - 1, 'O');
        	        break;
        	    case 'C':
        		    fill(0, N - 1, 0, M - 1, 'O');
        		    break;
        		case 'L':
        	        X = Integer.parseInt(tokens[1]);
        	        Y = Integer.parseInt(tokens[2]);
        			table[Y - 1][X - 1] = tokens[3].charAt(0);
        			break;
        		case 'V':
        		    X = Integer.parseInt(tokens[1]);
        	        Y1 = Integer.parseInt(tokens[2]);
        	        Y2 = Integer.parseInt(tokens[3]);
        			if(Y1 > Y2) {
        			    int temp = Y1;
        			    Y1 = Y2;
        			    Y2 = temp;
        			}
        			for(int i = Y1 - 1; i <= Y2 - 1; ++i)
        				table[i][X - 1] = tokens[4].charAt(0);
        			break;
        		case 'H':
        		    X1 = Integer.parseInt(tokens[1]);
        	        X2 = Integer.parseInt(tokens[2]);
        	        Y = Integer.parseInt(tokens[3]);
        			if(X1 > X2) {
        			    int temp = X1;
        			    X1 = X2;
        			    X2 = temp;
        			}
        			Arrays.fill(table[Y - 1], X1 - 1, X2, tokens[4].charAt(0));
        			break;
        		case 'K':
        		    X1 = Integer.parseInt(tokens[1]);
        	        Y1 = Integer.parseInt(tokens[2]);
        	        X2 = Integer.parseInt(tokens[3]);
        	        Y2 = Integer.parseInt(tokens[4]);
        			fill(Y1 - 1, Y2 - 1, X1 - 1, X2 - 1, tokens[5].charAt(0));
        			break;
        		case 'F':
        	        X = Integer.parseInt(tokens[1]);
        	        Y = Integer.parseInt(tokens[2]);
        			dfs(Y - 1, N, X - 1, M, table[Y - 1][X - 1], tokens[3].charAt(0));
        			break;
        		case 'S':
        			output.append(tokens[1] + "\n");
        			for(int i = 0; i < N; ++i) {
        			    for(int j = 0; j < M; ++j)
        			        output.append(table[i][j]);
        			    output.append("\n");
        			}
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
            for(int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                if(newRow >= 0 && newRow < rowLimit && newCol >= 0 && newCol < colLimit && table[newRow][newCol] == R)
                    dfs(newRow, rowLimit, newCol, colLimit, R, C);
            }
        }
    }
}
