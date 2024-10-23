import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0, N, Q;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (Q = (int)st.nval) != 0) {
		    output.append("CASE# ").append(++cases).append(":\n");
		    short[] marbles = new short[N];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        marbles[i] = (short)st.nval;
		    }
		    Arrays.sort(marbles);
		    while(Q-- > 0) {
		        st.nextToken();
		        short query = (short)st.nval;
		        int pos = binarySearch(marbles, query);
		        if(pos != 0)
		            output.append(query).append(" found at ").append(pos).append('\n');
		        else
		            output.append(query).append(" not found\n");
		    }
		}
		System.out.print(output);
	}
	
	static int binarySearch(short[] array, short key) {
        int left = 0, right = array.length - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(array[mid] == key) {
                while(mid > left && array[mid] == array[mid-1])
                    --mid;
                return mid + 1;
            }
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
}
