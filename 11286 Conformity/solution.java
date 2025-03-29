import java.io.*;
import java.util.*;

public class Main {
    static short[] courses = new short[5];;
    public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    int n;
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	        Map<Long, Short> combinations = new HashMap<>();
    		while(n-- > 0) {
    	        for(int i = 0; i < 5; ++i) {
    	            st.nextToken();
    	            courses[i] = (short)st.nval;
    	        }
    	        Arrays.sort(courses);
    	        long temp = 0;
    	        for(Short s : courses)
    	            temp = 1000 * temp + s;
    	        combinations.put(temp, (short)(combinations.getOrDefault(temp, (short)0) + 1));
    		}
    		short max = 0, students = 0;
    		for(Short s : combinations.values()) {
    		    if(max < s)
    		        students = max = s;
    		    else if(max == s)
    		        students += max;
    		}
    	    output.append(students).append('\n');
	    }
	    System.out.print(output);
	}
}
