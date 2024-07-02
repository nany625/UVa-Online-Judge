import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            int number;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (number = (int)st.nval) != 0) {
                System.out.println("Original number was " + number);
    			ArrayList<Integer> numbers = new ArrayList<>();
    			do {
    				numbers.add(number);
    				char[] newNumber = ("" + number).toCharArray();
    				Arrays.sort(newNumber);
    				int asc = Integer.parseInt(new String(newNumber)), len = newNumber.length;
    				for(int i = 0; i < len / 2; ++i)
    				    swap(newNumber, i, len - 1 - i);
    				int desc = Integer.parseInt(new String(newNumber));
    				System.out.println(desc + " - " + asc + " = " + (desc - asc));
    				number = desc - asc;
    			} while(!numbers.contains(number));
    			System.out.println("Chain length " + numbers.size() + "\n");
    		}
        } catch(IOException e) {};
	}
	
	static void swap(char[] array, int i, int j) {
	    char temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	}
}
