import java.io.*;
import java.util.*;

public class Main {
    static int[] count = new int[6];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer st = new StreamTokenizer(br);
	public static void main(String[] args) throws IOException {
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(!lastCase()) {
		    int sum = 0;
		    for(int i = 0; i < 6; ++i)
		        sum += (i + 1) * count[i];
		    if((sum & 1) == 1)
		        output.append("Collection #").append(++cases).append(":\nCan't be divided.\n\n");
		    else {
		        ArrayList<Integer> marbles = new ArrayList<>();
		        for(int i = 0; i < 6; ++i) {
                    for(int j = 1; j <= count[i]; j <<= 1) {
                        marbles.add((i + 1) * j);
                        count[i] -= j;
                    }
                    if(count[i] > 0)
                        marbles.add((i + 1) * count[i]);
                }
                output.append("Collection #").append(++cases).append(isSubsetSum(marbles, marbles.size(), sum >> 1) ? ":\nCan be divided.\n\n" : ":\nCan't be divided.\n\n");
		    }
		}
		System.out.print(output);
	}
	
	static boolean lastCase() throws IOException {
        boolean result = true;
        for(int i = 0; i < 6; ++i) {
            st.nextToken();
            result &= (count[i] = (int)st.nval) == 0;
        }
        return result;
    }
    
    static boolean isSubsetSum(ArrayList<Integer> arrayList, int size, int sum) {
        boolean[] subsetSum = new boolean[sum + 1];
        subsetSum[0] = true;
        for(int i = 0; i < size && !subsetSum[sum]; ++i) {
            for(int j = sum; j >= arrayList.get(i) && !subsetSum[sum]; --j)
                subsetSum[j] |= subsetSum[j - arrayList.get(i)];
        }
        return subsetSum[sum];
    }
}
