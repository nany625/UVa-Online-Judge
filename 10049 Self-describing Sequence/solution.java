import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Integer> f = new ArrayList<>();
    static int size = 1;
	public static void main(String[] args) throws IOException {
        f.add(1);
        int pos = 0;
        while(f.get(size - 1) <= 2000000000) {
            f.add(f.get(size - 1) + (pos += (size >= f.get(pos) ? 1 : 0)));
            ++size;
        }
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while((st.nextToken()) == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
		    output.append(binarySearch(n)).append('\n');
		System.out.print(output);
	}
	
	static int binarySearch(int key) {
	    int left = 0, right = size - 2;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(f.get(mid) == key)
                return mid + 1;
            if(f.get(mid) < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
	}
}
