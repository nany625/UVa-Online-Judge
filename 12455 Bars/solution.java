import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        st.nextToken();
	        int t = (int)st.nval;
	        while(t-- > 0) {
	            st.nextToken();
    	        int n = (int)st.nval;
    	        st.nextToken();
    	        int p = (int)st.nval;
        		short[] barsLen = new short[p];
        		for(int i = 0; i < p; ++i) {
        		    st.nextToken();
        			barsLen[i] = (short)st.nval;
        		}
        		System.out.println(isSubsetSum(barsLen, n) ? "YES" : "NO");
	        }
	    } catch(IOException e) {}
	}
	
	static boolean isSubsetSum(short[] array, int sum) {
        boolean[] subsetSum = new boolean[sum + 1];
        subsetSum[0] = true;
        int size = array.length;
        for(int i = 0; i < size; ++i) {
            for(int j = sum; j >= array[i]; --j) {
                if(subsetSum[j - array[i]])
                    subsetSum[j] = true;
            }
        }
        return subsetSum[sum];
    }
}
