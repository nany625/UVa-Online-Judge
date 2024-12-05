import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		short n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (short)st.nval) != -1) {
		    if(cases > 0)
		        output.append('\n');
		    ArrayList<Short> heights = new ArrayList<>(Arrays.asList(n));
		    while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (short)st.nval) != -1)
		        heights.add(n);
		    ArrayList<Short> lis = new ArrayList<>();
		    for(int i = heights.size() - 1; i >= 0; --i) {
		        int pos = binarySearch(lis, heights.get(i));
		        if(pos == lis.size())
		            lis.add(heights.get(i));
		        else
		            lis.set(pos, heights.get(i));
		    }
		    output.append("Test #").append(++cases).append(":\n  maximum possible interceptions: ").append(lisSize).append('\n');
		}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Short> arrayList, short key) {
        int left = 0, right = arrayList.size() - 1;
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
