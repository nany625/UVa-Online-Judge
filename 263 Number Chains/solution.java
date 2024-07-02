import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String number;
            while(!(number = br.readLine()).equals("0")) {
                System.out.println("Original number was " + number);
    			HashMap<String, Boolean> numbers = new HashMap<>();
    			do {
    				numbers.put(number, true);
    				char[] newNumber = number.toCharArray();
    				Arrays.sort(newNumber);
    				int asc = Integer.parseInt(new String(newNumber)), len = newNumber.length;
    				for(int i = 0; i < len / 2; ++i)
    				    swap(newNumber, i, len - 1 - i);
    				int desc = Integer.parseInt(new String(newNumber));
    				System.out.println(desc + " - " + asc + " = " + (desc - asc));
    				number = "" + (desc - asc);
    			} while(!numbers.containsKey(number));
    			System.out.println("Chain length " + numbers.size());
    			System.out.println();
    		}
        } catch(IOException e) {};
	}
	
	static void swap(char[] array, int i, int j) {
	    char temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	}
}
