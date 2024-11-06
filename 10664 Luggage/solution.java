import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(cases-- > 0) {
    	    String[] tokens = br.readLine().split("\\s+");
    	    int[] weights = new int[tokens.length];
            int sum = 0;
    	    for(int i = 0; i < tokens.length; ++i)
    	        sum += weights[i] = Integer.parseInt(tokens[i]);
    	    if((sum & 1) == 1)
    	        output.append("NO\n");
    	    else
    	        output.append(isSubsetSum(weights, sum >> 1) ? "YES\n" : "NO\n");
    	}
        System.out.print(output);
	}
	
	static boolean isSubsetSum(int[] array, int sum) {
        boolean[] subsetSum = new boolean[sum + 1];
        subsetSum[0] = true;
        for(int i = 0; i < array.length && !subsetSum[sum]; ++i) {
            for(int j = sum; j >= array[i] && !subsetSum[sum]; --j)
                subsetSum[j] |= subsetSum[j - array[i]];
        }
        return subsetSum[sum];
    }
}
