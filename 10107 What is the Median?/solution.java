import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Integer> numbers = new ArrayList<>();
        int size = 0;
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int X = (int)st.nval;
    	    numbers.add(X);
    	    int pos = size++;
    	    while(pos > 0 && X < numbers.get(pos - 1)) {
    	        numbers.set(pos, numbers.get(pos - 1));
    	        --pos;
    	    }
    	    numbers.set(pos, X);
    	    if((size & 1) == 1)
    	        output.append(numbers.get(size >> 1)).append('\n');
    	    else
    	        output.append(numbers.get((size >> 1) - 1) + ((numbers.get(size >> 1) - numbers.get((size >> 1) - 1)) >> 1)).append('\n');
    	}
        System.out.print(output);
	}
}
