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
	        long[] combinations = new long[n];
    		for(int i = 0; i < n; ++i) {
    		    for(int j = 0; j < 5; ++j) {
    		        st.nextToken();
    		        courses[j] = (short)st.nval;
    		    }
    		    Arrays.sort(courses);
    		    for(int j = 0; j < 5; ++j)
    		        combinations[i] = 1000 * combinations[i] + courses[j];
    		}
    		Arrays.sort(combinations);
    		int max = 1, students = 0, count = 1;
    		for(int i = 1; i < n; ++i) {
    		    if(combinations[i] == combinations[i - 1])
    		        ++count;
    		    else {
    		        if(max < count)
        		        students = max = count;
        		    else if(max == count)
        		        students += max;
        		    count = 1;
    		    }
    		}
    		if(max < count)
            	students = max = count;
            else if(max == count)
                students += max;
    	    output.append(students).append('\n');
	    }
	    System.out.print(output);
	}
}
