import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        HashMap<Integer, Solution> map = new HashMap<>();
        for(int y = 1; y <= 57; ++y) {
            for(int x = y + 1; x * x * x - y * y * y <= 10000; ++x) {
                int N = x * x * x - y * y * y;
                if(!map.containsKey(N))
                    map.put(N, new Solution((short)x, (short)y));
            }
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            if(map.containsKey(N))
                output.append(map.get(N).x + " " + map.get(N).y + "\n");
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
