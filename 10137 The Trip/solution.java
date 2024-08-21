import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            double[] expense = new double[n];
    	    int total = 0;
    	    for(int i = 0; i < n; ++i) {
    	        st.nextToken();
    	        total += expense[i] = Math.round(st.nval * 100);
    	    }
    	    Arrays.sort(expense);
    	    int overpayCount = total % n, average = total / n;
    	    int[] exchange = new int[2];
    	    for(int i = 0; i < n - overpayCount; ++i) {
    	        if(expense[i] < average)
    	            exchange[0] += average - expense[i];
    	        else
    	            exchange[1] += expense[i] - average;
    	    }
     	    for(int i = n - overpayCount; i < n; ++i) {
    	        if(expense[i] < average + 1)
    	            exchange[0] += (average + 1) - expense[i];
    	        else
    	            exchange[1] += expense[i] - (average + 1);
    	    }
    	    output.append(String.format("$%.2f%n", Math.min(exchange[0] / 100.0, exchange[1] / 100.0)));
        }
        System.out.print(output);
	}
}
