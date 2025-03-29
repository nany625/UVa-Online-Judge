import java.io.*;

public class Main {
    static int MAXN = 10000;
    static Solution[] solutions = new Solution[MAXN + 1];
    static boolean[] table = new boolean[MAXN + 1];
	public static void main(String[] args) throws IOException {
        for(short y = 1; y <= 57; ++y) {
            int N;
            for(short x = (short)(y + 1); (N = x * x * x - y * y * y) <= MAXN; ++x) {
                if(!table[N]) {
                    table[N] = true;
                    solutions[N] = new Solution(x, y);
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            if(table[N])
                output.append(solutions[N].x).append(' ').append(solutions[N].y).append('\n');
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
