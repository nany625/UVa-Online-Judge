import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
        for(int i = 0; i < size && !subsetSum[sum]; ++i) {
            for(int j = sum; j >= array[i] && !subsetSum[sum]; --j)
                subsetSum[j] |= subsetSum[j - array[i]];
        }
        return subsetSum[sum];
    }
}
