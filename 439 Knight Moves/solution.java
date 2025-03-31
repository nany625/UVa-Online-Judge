import java.io.*;
import java.util.*;

public class Main {
    static int[] dRow = {2, 2, 1, 1, -1, -1, -2, -2}, dCol = {1, -1, 2, -2, 2, -2, 1, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder output = new StringBuilder();
		while((line = br.readLine()) != null) {
		    if(line.substring(0, 2).equals(line.substring(3, 5)))
		        output.append("To get from ").append(line.substring(0, 2)).append(" to ").append(line.substring(3, 5)).append(" takes 0 knight moves.\n");
		    else {
		        ArrayList<Square> curr = new ArrayList<>();
    		    curr.add(new Square(line.charAt(1) - '1', line.charAt(0) - 'a'));
    		    int endRow = line.charAt(4) - '1', endCol = line.charAt(3) - 'a', currSize = 1, move = 1;
    		    boolean[][] visited = new boolean[8][8];
    		    visited[curr.get(0).row][curr.get(0).col] = true;
    		    boolean found = false;
    		    while(!found) {
    		        ArrayList<Square> next = new ArrayList<>();
    		        for(Square s : curr) {
    		            for(int i = 0; i < 8 && !found; ++i) {
    		                int newRow = s.row + dRow[i];
    		                int newCol = s.col + dCol[i];
    		                if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                                if(newRow == endRow && newCol == endCol) {
                                    output.append("To get from ").append(line.substring(0, 2)).append(" to ").append(line.substring(3, 5)).append(" takes ").append(move).append(" knight moves.\n");
                                    found = true;
                                } else if(!visited[newRow][newCol]) {
                                    next.add(new Square(newRow, newCol));
                                    visited[newRow][newCol] = true;
                                }
                            }
    		            }
    		        }
    		        curr = new ArrayList<>(next);
    		        ++move;
    		    }
		    }
		}
        System.out.print(output);
	}
}

class Square {
    int row, col;
    Square(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
