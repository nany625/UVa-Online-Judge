// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    int[] weights = new int[2 * n];
		    for(int i = 0; i < n; ++i) {
		        st.nextToken();
		        weights[n + i] = weights[n - 1 - i] = (int)st.nval;
		    }
		    ArrayList<Integer> lis = new ArrayList<>();
		    int size = 0;
		    for(int i = 2 * n - 1; i >= 0; --i) {
                int pos = binarySearch(lis, size, weights[i]);
                if(pos == size) {
                    lis.add(weights[i]);
                    ++size;
                } else
                    lis.set(pos, weights[i]);
            }
            output.append(size).append('\n');
		}
		System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Integer> arrayList, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
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

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    int[] weights = new int[n];
		    for(int i = 0; i < n; ++i) {
		        st.nextToken();
		        weights[i] = (int)st.nval;
		    }
		    ArrayList<Integer> lis = new ArrayList<>();
		    ArrayList<Integer> lds = new ArrayList<>();
		    int lisSize = 0, ldsSize = 0, max = 0;
		    for(int i = n - 1; i >= 0; --i) {
                int left = 0, right = lisSize - 1;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(lis.get(mid) < weights[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                if(left == lisSize) {
                    lis.add(weights[i]);
                    ++lisSize;
                } else
                    lis.set(left, weights[i]);
                int temp = left + 1;
                left = 0;
                right = ldsSize - 1;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(lds.get(mid) > weights[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                if(left == ldsSize) {
                    lds.add(weights[i]);
                    ++ldsSize;
                } else
                    lds.set(left, weights[i]);
                temp += left;
                max = Math.max(max, temp);
            }
            output.append(max).append('\n');
		}
		System.out.print(output);
	}
}
