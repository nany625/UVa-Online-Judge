import java.io.*;
import java.util.*;

public class Main {
    static char[][] screen = new char[10][10];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            output.append("Case ").append(++cases).append('\n');
    		for(int i = 0; i < 10; ++i)
    	        Arrays.fill(screen[i], ' ');
    	    int cursorRow = 0, cursorCol = 0;
    	    boolean override = true;
    	    while(N-- > 0) {
    	        String data = br.readLine();
    	        for(int i = 0; i < data.length(); ++i) {
    	            if(data.charAt(i) == '^') {
    	                char control = data.charAt(++i);
    	                if(control == 'b')
    	                    cursorCol = 0;
    	                else if(control == 'c') {
                            for(int j = 0; j < 10; ++j)
                                Arrays.fill(screen[j], ' ');
    	                } else if(control == 'd') {
    	                    if(cursorRow < 9)
    	                        ++cursorRow;
    	                } else if(control == 'e')
    	                    Arrays.fill(screen[cursorRow], cursorCol, 10, ' ');
    	                else if(control == 'h')
    	                    cursorRow = cursorCol = 0;
    	                else if(control == 'i')
    	                    override = false;
    	                else if(control == 'l') {
    	                    if(cursorCol > 0)
    	                        --cursorCol;
    	                } else if(control == 'o')
    	                    override = true;
    	                else if(control == 'r') {
    	                    if(cursorCol < 9)
    	                        ++cursorCol;
    	                } else if(control == 'u') {
    	                    if(cursorRow > 0)
    	                        --cursorRow;
    	                } else if(Character.isDigit(control)) {
    	                    cursorRow = control - '0';
    	                    cursorCol = data.charAt(++i) - '0';
    	                } else {
    	                    write(cursorRow, cursorCol, control, override);
    	                    cursorCol = cursorCol < 9 ? cursorCol + 1 : cursorCol;
    	                }
    	            } else {
    	                write(cursorRow, cursorCol, data.charAt(i), override);
    	                cursorCol = cursorCol < 9 ? cursorCol + 1 : cursorCol;
    	            }
    	        }
    	    }
    	    output.append("+----------+\n");
    	    for(int i = 0; i < 10; ++i)
		    	output.append('|').append(new String(screen[i])).append("|\n");
		    output.append("+----------+\n");
        }
	    System.out.print(output);
	}
	
	static void write(int row, int col, char ch, boolean override) {
        if(override)
    	    screen[row][col] = ch;
    	else {
    	    System.arraycopy(screen[row], col, screen[row], col + 1, 9 - col);
    	    screen[row][col] = ch;
    	}
    }
}
