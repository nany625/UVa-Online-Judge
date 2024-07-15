import java.io.*;

public class Main {
    static Card[][] bingo = new Card[5][5];
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    for(int i = 0; i < 5; ++i) {
    			for(int j = 0; j < 5; ++j) {
    			    if(i == 2 && j == 2) {
    				    bingo[i][j] = new Card((short)0, true);
    					continue;
    				}
    			    st.nextToken();
    			    bingo[i][j] = new Card((short)st.nval, false);
    			}
    		}
    		boolean win = false;
    		for(int i = 1; i <= 75; ++i) {
    		    st.nextToken();
    		    short order = (short)st.nval;
    		    if(!win) {
    		        int col = (order - 1) / 15, row = 0;
        		    while(row < 5 && bingo[row][col].num != order) 
        		        ++row;
        		    if(row < 5) {
        		        bingo[row][col].announce = true;
        		        if(i >= 4)
        		            win = isBINGO(row, col);
        		    }
        		    if(win)
        		        output.append("BINGO after " + i + " numbers announced\n");
    		    }
    		}
		}
		System.out.print(output);
	}
	
	static boolean isBINGO(int row, int col) {
        int i = 0;
        while(i < 5 && bingo[row][i].announce)
            ++i;
        if(i == 5)
            return true;
        i = 0;
        while(i < 5 && bingo[i][col].announce)
            ++i;
        if(i == 5)
            return true;
        if(row == col || row + col == 4) {
            i = 0;
            while(i < 5 && bingo[i][i].announce)
                ++i;
            if(i == 5)
                return true;
            i = 0;
            while(i < 5 && bingo[i][4 - i].announce)
                ++i;
            if(i == 5)
                return true;
        }
        return false;
    }
}

class Card {
    short num;
    boolean announce;
    Card(short num, boolean announce) {
        this.num = num;
        this.announce = announce;
    }
}v
