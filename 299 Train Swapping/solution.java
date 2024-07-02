import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int N = (int)st.nval;
            while(N-- > 0) {
                st.nextToken();
                int L = (int)st.nval, swap = 0;
    	        int[] a = new int[L];
    	        for(int i = 0; i < L; ++i) {
    	            st.nextToken();
    	            a[i] = (int)st.nval;
    	            for(int j = 0; j < i; ++j) {
                        if(a[j] > a[i])
                            ++swap;
                    }
    	        }
    	        System.out.println("Optimal train swapping takes " + swap + " swaps.");
    		}
        } catch(IOException e) {};
	}
}
