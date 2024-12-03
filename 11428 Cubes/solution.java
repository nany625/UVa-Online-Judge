import java.io.*;

public class Main {
    static int MAX_NUM = 10000;
	public static void main(String[] args) throws IOException {
        Solution[] solutions = new Solution[MAX_NUM];
        boolean[] table = new boolean[MAX_NUM];
        for(short y = 1; y <= 57; ++y) {
            int N;
            for(short x = (short)(y + 1); (N = x * x * x - y * y * y) <= MAX_NUM; ++x) {
                if(!table[N - 1]) {
                    table[N - 1] = true;
                    solutions[N - 1] = new Solution(x, y);
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            if(table[N - 1])
                output.append(solutions[N - 1].x).append(' ').append(solutions[N - 1].y).append('\n');
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
