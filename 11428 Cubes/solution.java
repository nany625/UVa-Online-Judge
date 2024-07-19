import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        Solution[] solutions = new Solution[10000];
        boolean[] table = new boolean[10000];
        for(short y = 1; y <= 57; ++y) {
            for(short x = (short)(y + 1); x * x * x - y * y * y <= 10000; ++x) {
                int N = x * x * x - y * y * y;
                if(!table[N - 1]) {
                    table[N - 1] = true;
                    solutions[N - 1] = new Solution(x, y);
                }
            }
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            if(table[N - 1])
                output.append(solutions[N - 1].x + " " + solutions[N - 1].y + "\n");
            else
                output.append("No solution\n");
        }
        System.out.print(output);
	}
}

class Solution {
    short x, y;
    Solution(short x, short y) {
        this.x = x;
        this.y = y;
    }
}
