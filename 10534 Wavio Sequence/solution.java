import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int N = (int)st.nval, lisSize = 0;
            int[] sequence = new int[N], lisDP = new int[N];
            ArrayList<Integer> LIS = new ArrayList<>();
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                sequence[i] = (int)st.nval;
                int pos = binarySearch(LIS, lisSize, sequence[i]);
                if(pos == lisSize) {
                    LIS.add(sequence[i]);
                    ++lisSize;
                } else
                    LIS.set(pos, sequence[i]);
                lisDP[i] = pos + 1;
            }
            int ldsSize = 0, max = 1;
            int[] ldsDP = new int[N];
            ArrayList<Integer> LDS = new ArrayList<>();
            for(int i = N - 1; i >= 0 && max < lisSize; --i) {
                int pos = binarySearch(LDS, ldsSize, sequence[i]);
                if(pos == ldsSize) {
                    LDS.add(sequence[i]);
                    ++ldsSize;
                } else
                    LDS.set(pos, sequence[i]);
                ldsDP[i] = pos + 1;
                max = Math.max(max, Math.min(lisDP[i], ldsDP[i]));
            }
            output.append((max << 1) - 1).append('\n');
    	}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Integer> arrayList, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
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
