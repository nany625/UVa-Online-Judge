import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int p = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(p-- > 0) {
		    st.nextToken();
		    int floors = (int)st.nval;
		    int[] size = new int[floors];
		    for(int i = 0; i < floors; ++i) {
		        st.nextToken();
		        size[i] = (int)st.nval;
		    }
		    Arrays.sort(size);
		    int leftPointer = binarySearch(size, 0), rightPointer = leftPointer, above = size[leftPointer], count = (floors > 0 ? 1 : 0);
		    while(leftPointer >= 0 && rightPointer < floors) {
    	        if(above > 0) {
    	            do {
    	                --leftPointer;
    	            } while(leftPointer >= 0 && size[leftPointer] + above > 0);
    	            if(leftPointer >= 0) {
    	                ++count;
    	                above = size[leftPointer];
    	            }
    	        } else {
    	            do {
    	                ++rightPointer;
    	            } while(rightPointer < floors && size[rightPointer] + above < 0);
    	            if(rightPointer < floors) {
    	                ++count;
    	                above = size[rightPointer];
    	            }
    	        }
    	    }
    	    output.append(count).append('\n');
		}
		System.out.print(output);
	}
	
	static int binarySearch(int[] array, int key) {
        int left = 0, right = array.length - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if(left == array.length || (left > 0 && array[left - 1] + array[left] > 0))
    	    --left;
        return left;
    }
}
