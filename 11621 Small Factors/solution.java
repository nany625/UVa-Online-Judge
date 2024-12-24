import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer> C = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		long i = 1;
		while(i <= 2147483647) {
		    long temp = i;
		    do {
		        C.add((int)temp);
		        temp *= 3;
		    } while(temp <= 2147483647);
		    i <<= 1;
		}
		Collections.sort(C);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int m;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (m = (int)st.nval) != 0) {
		    int pos = binarySearch(m);
		    output.append(pos < C.size() ? (long)C.get(pos) : 2147483648L).append('\n');
		}
		System.out.print(output);
	}
	
	static int binarySearch(int key) {
        int left = 0, right = C.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(C.get(mid) == key)
                return mid;
            if(C.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
