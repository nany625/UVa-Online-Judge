import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= t; ++i) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int p = (int)st.nval + 1;
            st.nextToken();
            int q = (int)st.nval + 1;
            int[] index = new int[n * n + 1];
            for(int j = 1; j <= p; ++j) {
                st.nextToken();
                index[(int)st.nval] = j;
            }
            ArrayList<Integer> lis = new ArrayList<>();
            int lisSize = 0;
            while(q-- > 0) {
                st.nextToken();
                int curr = index[(int)st.nval], pos = binarySearch(lis, lisSize, curr);
                if(pos == lisSize) {
                    lis.add(curr);
                    ++lisSize;
                } else
                    lis.set(pos, curr);
            }
            output.append("Case ").append(i).append(": ").append(lisSize).append('\n');
    	}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Integer> arrayList, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(arrayList.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
