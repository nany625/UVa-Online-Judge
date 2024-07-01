import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try {
    	    StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int sets = (int)st.nval;
            while(sets-- > 0) {
                st.nextToken();
                int N = (int)st.nval;
                if(N == 0) {
                    System.out.println(0);
				    continue;
                }
                ArrayList<Integer> factors = new ArrayList<>();
    			int curr = 9;
    			while(curr > 1) {
    				if(N % curr == 0) {
    					factors.add(curr);
    					N /= curr;
    				} else
    					--curr;
    			}
    			if(N == 1) {
    				if(factors.isEmpty())
    					System.out.println(1);
    				else {
    					for(curr = factors.size() - 1; curr >= 0; --curr)
    						System.out.print(factors.get(curr));
    					System.out.println();
    				}
    			} else
    				System.out.println(-1);
            }
	    } catch(IOException e) {}
	}
	
	static int binarySearch(int[] array, int key) {
	    int left = 0, right = 41;
		while(left <= right) {
			int mid = left + (right - left) / 2;
			if(array[mid] == key)
				return mid;
			if(array[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return left;
	}
}
