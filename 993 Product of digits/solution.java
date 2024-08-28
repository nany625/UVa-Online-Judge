import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int sets = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(sets-- > 0) {
            st.nextToken();
            int N = (int)st.nval;
            if(N == 0) {
                output.append("0\n");
			    continue;
            }
            ArrayList<Integer> factors = new ArrayList<>();
    		int curr = 9;
    		while(curr > 1) {
    			if(N % curr == 0) {
    				factors.add(curr);
    				N /= curr;
    			} else
    				--curr;
    		}
    		if(N == 1) {
    			if(factors.isEmpty())
    				output.append("1\n");
    			else {
    				for(curr = factors.size() - 1; curr >= 0; --curr)
    					output.append(factors.get(curr));
    				output.append('\n');
    			}
    		} else
    			output.append("-1\n");
        }
	    System.out.print(output);
	}
}
