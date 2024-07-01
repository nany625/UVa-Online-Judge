import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        short[] courses = new short[5];
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        int n;
	        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	            ArrayList<Combination> combinations = new ArrayList<>();
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
    		        int pos = binarySearch(combinations, temp);
    		        if(pos < combinations.size() && combinations.get(pos).froshes == temp) {
    		            ++combinations.get(pos).popularity;
    		            if(max < combinations.get(pos).popularity)
    		                students = max = combinations.get(pos).popularity;
    		            else if(max == combinations.get(pos).popularity)
    		                students += max;
    		        } else {
    		            combinations.add(pos, new Combination(temp, (short)1));
    		            if(max < 1)
        				    students = max = 1;
        				else if(max == 1)
        					++students;
    		        }
    		    }
    		    System.out.println(students);
	        }
	    } catch(IOException e) {}
	}
	
	static int binarySearch(ArrayList<Combination> arrayList, long key) {
        int left = 0, right = arrayList.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arrayList.get(mid).froshes == key)
                return mid;
            if(arrayList.get(mid).froshes < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

class Combination {
    long froshes;
    short popularity;
    Combination(long froshes, short popularity) {
        this.froshes = froshes;
        this.popularity = popularity;
    }
}
