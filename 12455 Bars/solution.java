import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
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
    		output.append(isSubsetSum(barsLen, n) ? "YES\n" : "NO\n");
        }
	    System.out.print(output);
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
