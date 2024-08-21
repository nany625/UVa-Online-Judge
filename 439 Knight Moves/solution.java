import java.io.*;
import java.util.*;

public class Main {
    static int[] dRow = {2, 2, 1, 1, -1, -1, -2, -2}, dCol = {1, -1, 2, -2, 2, -2, 1, -1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder output = new StringBuilder();
		while((line = br.readLine()) != null) {
		    if(line.charAt(0) == line.charAt(3) && line.charAt(1) == line.charAt(4)) {
		        output.append("To get from ").append(line.charAt(0)).append(line.charAt(1)).append(" to ").append(line.charAt(3)).append(line.charAt(4)).append(" takes 0 knight moves.\n");
		        continue;
		    }
		    ArrayList<Square> squares = new ArrayList<>();
		    squares.add(new Square(line.charAt(1) - '1', line.charAt(0) - 'a'));
		    int endRow = line.charAt(4) - '1', endCol = line.charAt(3) - 'a', currSize = 1, move = 1;
		    boolean[][] visited = new boolean[8][8];
		    visited[squares.get(0).row][squares.get(0).col] = true;
		    boolean found = false;
		    while(!found) {
		        ArrayList<Square> nextSquares = new ArrayList<>();
		        int nextSize = 0;
		        for(int i = 0; i < currSize && !found; ++i) {
		            for(int j = 0; j < 8; ++j) {
		                int newRow = squares.get(i).row + dRow[j];
		                int newCol = squares.get(i).col + dCol[j];
		                if(newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
                            if(newRow == endRow && newCol == endCol) {
                                output.append("To get from ").append(line.charAt(0)).append(line.charAt(1)).append(" to ").append(line.charAt(3)).append(line.charAt(4)).append(" takes ").append(move).append(" knight moves.\n");
                                found = true;
                            } else if(!visited[newRow][newCol]) {
                                nextSquares.add(new Square(newRow, newCol));
                                ++nextSize;
                                visited[newRow][newCol] = true;
                            }
                        }
		            }
		        }
		        squares = new ArrayList<>(nextSquares);
		        currSize = nextSize;
		        ++move;
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
