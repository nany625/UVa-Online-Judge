// #解法一(偷吃步)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    short[] ans = {
            1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 
            21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 
            42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 
            38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 
            38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 
            72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 
            67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 
            137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 
            49, 5, 22, 54, 52, 113, 15, 66
        };
        StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
            output.append(ans[N - 13] + "\n");
	    System.out.print(output);
	}
}

// #解法二(正規演算法)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    int N;
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int i, m = 0;
            do {
                ++m;
                boolean[] regionState = new boolean[N];
                regionState[0] = true;
                int turnOff = 1, wrapCount = 0;
                i = 1;
                while(turnOff < N) {
    	            if(i == N)
                        i = 1;
                    if(!regionState[i])
        	            ++wrapCount;
        	        if(wrapCount == m) {
        	            ++turnOff;
        	            regionState[i] = true;
        	            wrapCount = 0;
        	        }
        	        ++i;
                }
            } while(i != 13);
    		output.append(m + "\n");
        }
	    System.out.print(output);
	}
}
