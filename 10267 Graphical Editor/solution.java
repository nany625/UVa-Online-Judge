import java.io.*;
import java.util.*;

public class Main {
    static char[][] table = new char[250][250];
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	        StreamTokenizer st = new StreamTokenizer(br);
	        char command, C;
		    int M = 0, N = 0, X, X1, X2, Y, Y1, Y2;
    		while(st.nextToken() == StreamTokenizer.TT_WORD && (command = st.sval.charAt(0)) != 'X') {
    		    if(command == 'I') {
    		        st.nextToken();
    		        M = (int)st.nval;
    		        st.nextToken();
    		        N = (int)st.nval;
    		        fill(0, N - 1, 0, M - 1, 'O');
    		    } else if(command == 'C')
    			    fill(0, N - 1, 0, M - 1, 'O');
    			else if(command == 'L') {
        			st.nextToken();
    		        X = (int)st.nval;
    		        st.nextToken();
    		        Y = (int)st.nval;
    		        st.nextToken();
    		        C = st.sval.charAt(0);
        			table[Y - 1][X - 1] = C;
        		} else if(command == 'V') {
        		    st.nextToken();
        		    X = (int)st.nval;
    		        st.nextToken();
    		        Y1 = (int)st.nval;
    		        st.nextToken();
    		        Y2 = (int)st.nval;
    		        st.nextToken();
    		        C = st.sval.charAt(0);
        			if(Y1 > Y2) {
        			    int temp = Y1;
        			    Y1 = Y2;
        			    Y2 = temp;
        			}
        			for(int i = Y1 - 1; i <= Y2 - 1; ++i)
        				table[i][X - 1] = C;
        		} else if(command == 'H') {
        		    st.nextToken();
        		    X1 = (int)st.nval;
    		        st.nextToken();
    		        X2 = (int)st.nval;
    		        st.nextToken();
    		        Y = (int)st.nval;
    		        st.nextToken();
    		        C = st.sval.charAt(0);
        			if(X1 > X2) {
        			    int temp = X1;
        			    X1 = X2;
        			    X2 = temp;
        			}
        			Arrays.fill(table[Y - 1], X1 - 1, X2, C);
        		} else if(command == 'K') {
        		    st.nextToken();
        		    X1 = (int)st.nval;
    		        st.nextToken();
    		        Y1 = (int)st.nval;
    		        st.nextToken();
    		        X2 = (int)st.nval;
    		        st.nextToken();
    		        Y2 = (int)st.nval;
    		        st.nextToken();
    		        C = st.sval.charAt(0);
        			fill(Y1 - 1, Y2 - 1, X1 - 1, X2 - 1, C);
        		} else if(command == 'F') {
        			st.nextToken();
    		        X = (int)st.nval;
    		        st.nextToken();
    		        Y = (int)st.nval;
    		        st.nextToken();
    		        C = st.sval.charAt(0);
        			dfs(Y - 1, N, X - 1, M, table[Y - 1][X - 1], C);
        		} else if(command == 'S') {
        		    st.nextToken();
        			System.out.println(st.sval);
        			for(int i = 0; i < N; ++i)
        			    System.out.println(new String(table[i], 0, M));
        		} else
        		    br.readLine();
    		}
	    } catch(IOException e) {}
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
