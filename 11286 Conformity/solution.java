import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        short[] courses = new short[5];
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    int n;
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	        HashMap<Long, Short> combinations = new HashMap<>();
    		short max = 0, students = 0;
    		while(n-- > 0) {
    	        for(int i = 0; i < 5; ++i) {
    	            st.nextToken();
    	            courses[i] = (short)st.nval;
    	        }
    	        Arrays.sort(courses);
    	        long temp = 0;
    	        for(Short s : courses)
    	            temp = 1000 * temp + s;
    	        if(combinations.containsKey(temp))
    	            combinations.replace(temp, (short)(combinations.get(temp) + 1));
    	        else
    	            combinations.put(temp, (short)1);
    		    if(max < combinations.get(temp))
    	            students = max = combinations.get(temp);
    	        else if(max == combinations.get(temp))
    	            students += max;
    		}
    	    output.append(students + "\n");
	    }
	    System.out.print(output);
	}
}
