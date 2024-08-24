import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
		int cases = 0;
		short n;
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (short)st.nval) != -1) {
		    if(!firstCase)
		        output.append('\n');
		    ArrayList<Short> heights = new ArrayList<>(Arrays.asList(n));
		    while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (short)st.nval) != -1)
		        heights.add(n);
		    ArrayList<Short> lis = new ArrayList<>();
		    int lisSize = 0;
		    for(int i = heights.size() - 1; i >= 0; --i) {
		        int pos = binarySearch(lis, lisSize, heights.get(i));
		        if(pos == lisSize) {
		            lis.add(heights.get(i));
		            ++lisSize;
		        } else
		            lis.set(pos, heights.get(i));
		    }
		    output.append("Test #").append(++cases).append(":\n  maximum possible interceptions: ").append(lisSize).append('\n');
		    firstCase = false;
		}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Short> arrayList, int size, short key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arrayList.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
