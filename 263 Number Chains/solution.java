import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int number;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (number = (int)st.nval) != 0) {
            output.append("Original number was " + number + "\n");
    		ArrayList<Integer> numbers = new ArrayList<>();
			do {
    			numbers.add(number);
				char[] newNumber = ("" + number).toCharArray();
    			Arrays.sort(newNumber);
    			int asc = Integer.parseInt(new String(newNumber)), len = newNumber.length;
				for(int i = 0; i < len / 2; ++i)
    			    swap(newNumber, i, len - 1 - i);
    			int desc = Integer.parseInt(new String(newNumber));
				output.append(desc).append(" - ").append(asc).append(" = ").append(desc - asc).append('\n');
    			number = desc - asc;
    		} while(!numbers.contains(number));
			output.append("Chain length ").append(numbers.size()).append("\n\n");
    	}
        System.out.print(output);
	}
	
	static void swap(char[] array, int i, int j) {
	    char temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	}
}
