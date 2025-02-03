import java.io.*;
import java.util.*;

public class Main {
    static String[] grid = new String[10];
    static int[][] steps = new int[10][10];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int rows;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (rows = (int)st.nval) != 0) {
		    st.nextToken();
		    int cols = (int)st.nval;
		    st.nextToken();
		    int currCol = (int)st.nval;
		    for(int i = 0; i < rows; ++i) {
		        st.nextToken();
		        grid[i] = st.sval;
		    }
		    boolean exit = false;
		    int currRow = 0, step = 0;
		    for(int i = 0; i < rows; ++i)
		        Arrays.fill(steps[i], -1);
		    steps[currRow][--currCol] = 0;
		    while(true) {
		        ++step;
		        switch(grid[currRow].charAt(currCol)) {
		            case 'N':
                        --currRow;
                        break;
                    case 'E':
                        ++currCol;
                        break;
                    case 'S':
                        ++currRow;
                        break;
                    case 'W':
                        --currCol;
		        }
		        if(currRow == -1 || currRow == rows || currCol == -1 || currCol == cols) {
                    output.append(step).append(" step(s) to exit\n");
                    break;
                }
                if(steps[currRow][currCol] != -1) {
                    output.append(steps[currRow][currCol]).append(" step(s) before a loop of ").append(step - steps[currRow][currCol]).append(" step(s)\n");
                    break;
                }
                steps[currRow][currCol] = step;
		    }
		}
		System.out.print(output);
	}
}
