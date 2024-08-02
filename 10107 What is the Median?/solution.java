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
    	    if(size % 2 == 0)
    	        output.append(numbers.get(size / 2 - 1) + (numbers.get(size / 2) - numbers.get(size / 2 - 1)) / 2 + "\n");
    	    else
    	        output.append(numbers.get(size / 2) + "\n");
    	}
        System.out.print(output);
	}
}