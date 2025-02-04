import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    st.nextToken();
		    int q = (int)st.nval;
		    st.nextToken();
		    int prev = (int)st.nval;
		    ArrayList<Integer> indices = new ArrayList<>();
		    for(int i = 1; i < n; ++i) {
		        st.nextToken();
		        int curr = (int)st.nval;
		        if(prev != curr) {
		            indices.add(i);
		            prev = curr;
		        }
		    }
		    indices.add(n);
		    while(q-- > 0) {
		        st.nextToken();
    		    int i = (int)st.nval;
    		    st.nextToken();
    		    int j = (int)st.nval;
    		    int pos = binarySearch(indices, i);
    		    if(indices.get(pos) >= j)
    		        output.append(j - i + 1).append('\n');
    		    else {
    		        int max = indices.get(pos++) - i + 1;
    		        while(pos < indices.size() && indices.get(pos) < j) {
                        max = Math.max(max, indices.get(pos) - indices.get(pos - 1));
                        ++pos;
                    }
                    output.append(Math.max(max, j - indices.get(pos - 1))).append('\n');
    		    }
		    }
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
