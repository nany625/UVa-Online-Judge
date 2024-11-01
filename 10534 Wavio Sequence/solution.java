import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int N = (int)st.nval;
            int[] sequence = new int[N], lisDP = new int[N];
            ArrayList<Integer> LIS = new ArrayList<>();
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                sequence[i] = (int)st.nval;
                int pos = binarySearch(LIS, sequence[i]);
                if(pos == LIS.size())
                    LIS.add(sequence[i]);
                else
                    LIS.set(pos, sequence[i]);
                lisDP[i] = pos + 1;
            }
            int max = 1;
            int[] ldsDP = new int[N];
            ArrayList<Integer> LDS = new ArrayList<>();
            for(int i = N - 1; i >= 0 && max < lisSize; --i) {
                int pos = binarySearch(LDS, sequence[i]);
                if(pos == LDS.size())
                    LDS.add(sequence[i]);
                else
                    LDS.set(pos, sequence[i]);
                ldsDP[i] = pos + 1;
                max = Math.max(max, Math.min(lisDP[i], ldsDP[i]));
            }
            output.append((max << 1) - 1).append('\n');
    	}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Integer> arrayList, int key) {
        int left = 0, right = arrayList.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(arrayList.get(mid) == key)
                return mid;
            if(arrayList.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
