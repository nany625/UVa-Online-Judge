import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= cases; ++i) {
	        if(i > 1)
	            output.append('\n');
	        output.append("Case ").append(i).append(":\n");
	        short[] costs = new short[36];
	        for(int j = 0; j < 36; ++j) {
	            st.nextToken();
	            costs[j] = (short)st.nval;
	        }
	        st.nextToken();
	        int queries = (int)st.nval;
	        while(queries-- > 0) {
	            st.nextToken();
	            int number = (int)st.nval;
	            short cheapest = 0;
	            short[] totalCosts = new short[35];
	            for(int base = 2; base <= 36; ++base) {
	                int temp = number;
	                do {
    					totalCosts[base - 2] += costs[temp % base];
    					temp /= base;
    				} while(temp > 0);
    				if(cheapest > totalCosts[base - 2] || cheapest == 0)
    				    cheapest = totalCosts[base - 2];
	            }
	            output.append("Cheapest base(s) for number ").append(number).append(':');
	            for(int base = 2; base <= 36; ++base) {
    				if(totalCosts[base - 2] == cheapest)
    					output.append(' ').append(base);
    			}
    			output.append('\n');
	        }
        }
        System.out.print(output);
    }	
}
