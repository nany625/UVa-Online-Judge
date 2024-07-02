import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    		    int n = (int)st.nval;
    	        int[] X = new int[n];
    	        for(int i = 0; i < n; ++i) {
    	            st.nextToken();
    	            X[i] = (int)st.nval;
    	        }
    	        Arrays.sort(X);
    	        int low = (n - 1) / 2, high = n / 2;
                while(low > 0 && X[low] == X[low - 1])
                    --low;
                while(high < n - 1 && X[high] == X[high + 1])
                    ++high;
                System.out.println(X[(n - 1) / 2] + " " + (high - low + 1) + " " + (X[n / 2] - X[(n - 1) / 2] + 1));
    		}
        } catch(IOException e) {};
	}
}
