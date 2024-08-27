import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int n = (int)st.nval;
            int[] X = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                X[i] = (int)st.nval;
            }
            Arrays.sort(X);
            int low = (n - 1) >> 1, high = n >> 1;
            while(low > 0 && X[low] == X[low - 1])
                --low;
            while(high < n - 1 && X[high] == X[high + 1])
                ++high;
            output.append(X[(n - 1) >> 1]).append(' ').append(high - low + 1).append(' ').append(X[n >> 1] - X[(n - 1) >> 1] + 1).append('\n');
    	}
    	System.out.print(output);
	}
}
