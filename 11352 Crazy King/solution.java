import java.io.*;
import java.util.*;

public class Main {
    static int[] horsedRow = {2, 2, 1, 1, -1, -1, -2, -2}, horsedCol = {1, -1, 2, -2, 2, -2, 1, -1};
    static int[] kingdRow = {1, 1, 1, -1, -1, -1, 0, 0}, kingdCol = {1, 0, -1, 1, 0, -1, 1, -1};
    static char[][] forest = new char[100][100];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            st.nextToken();
            int M = (int)st.nval;
            st.nextToken();
            int N = (int)st.nval;
            for(int i = 0; i < M; ++i)
                forest[i] = br.readLine().toCharArray();
            for(int i = 0; i < M; ++i) {
                for(int j = 0; j < N; ++j) {
                    if(forest[i][j] == 'Z') {
                        for(int k = 0; k < 8; ++k) {
                            int newRow = i + horsedRow[k], newCol = j + horsedCol[k];
                            if(newRow >= 0 && newRow < M && newCol >= 0 && newCol < N && forest[newRow][newCol] == '.')
                                forest[newRow][newCol] = 'z';
                        }
                    }
                }
            }
            int kingRow = 0, kingCol = 0;
            while(forest[kingRow][kingCol] != 'A') {
                ++kingCol;
                if(kingCol == N) {
                    ++kingRow;
                    kingCol = 0;
                }
            }
            forest[kingRow][kingCol] = 'z';
            ArrayList<Coordinate> curr = new ArrayList<>();
            curr.add(new Coordinate(kingRow, kingCol));
            boolean safe = false;
            int length = 1;
            while(!curr.isEmpty() && !safe) {
                ArrayList<Coordinate> next = new ArrayList<>();
                for(Coordinate c : curr) {
                    for(int i = 0; i < 8 && !safe; ++i) {
                        int newRow = c.row + kingdRow[i];
                        int newCol = c.col + kingdCol[i];
                        if(newRow >= 0 && newRow < M && newCol >= 0 && newCol < N) {
                            if(forest[newRow][newCol] == 'B') {
                                output.append("Minimal possible length of a trip is ").append(length).append('\n');
                                safe = true;
                            } else if(forest[newRow][newCol] == '.') {
                                next.add(new Coordinate(newRow, newCol));
                                forest[newRow][newCol] = 'z';
                            }
                        }
                    }
                }
                curr = new ArrayList<>(next);
                ++length;
            }
            if(!safe)
                output.append("King Peter, you can't go now!\n");
        }
	    System.out.print(output);
	}
}

class Coordinate {
    int row, col;
    Coordinate(int row, int col) {
        this.row = row;
        this.col = col;
    }
}
