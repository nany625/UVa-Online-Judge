import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Integer> numbers = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int X = (int)st.nval;
    	    numbers.add(X);
    	    int pos = numbers.size() - 1;
    	    while(pos > 0 && X < numbers.get(pos - 1)) {
    	        numbers.set(pos, numbers.get(pos - 1));
    	        --pos;
    	    }
    	    numbers.set(pos, X);
    	    if((numbers.size() & 1) == 1)
    	        output.append(numbers.get(numbers.size() >> 1)).append('\n');
    	    else
    	        output.append(numbers.get((numbers.size() >> 1) - 1) + ((numbers.get(numbers.size() >> 1) - numbers.get((numbers.size() >> 1) - 1)) >> 1)).append('\n');
    	}
        System.out.print(output);
	}
}
