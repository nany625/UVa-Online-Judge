// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    int[] weights = new int[n << 1];
		    for(int i = 0; i < n; ++i) {
		        st.nextToken();
		        weights[n + i] = weights[n - 1 - i] = (int)st.nval;
		    }
		    ArrayList<Integer> lis = new ArrayList<>();
		    for(int i = (n << 1) - 1; i >= 0; --i) {
                int pos = binarySearch(lis, weights[i]);
                if(pos == lis.size())
                    lis.add(weights[i]);
                else
                    lis.set(pos, weights[i]);
            }
            output.append(lis.size()).append('\n');
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

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
		    int max = 0;
		    for(int i = n - 1; i >= 0; --i) {
                int left = 0, right = lis.size() - 1;
                while(left <= right) {
                    int mid = left + (right - left >> 1);
                    if(lis.get(mid) < weights[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                if(left == lis.size())
                    lis.add(weights[i]);
                else
                    lis.set(left, weights[i]);
                int temp = left + 1;
                left = 0;
                right = lds.size() - 1;
                while(left <= right) {
                    int mid = left + (right - left >> 1);
                    if(lds.get(mid) > weights[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                if(left == lds.size())
                    lds.add(weights[i]);
                else
                    lds.set(left, weights[i]);
                temp += left;
                max = Math.max(max, temp);
            }
            output.append(max).append('\n');
		}
		System.out.print(output);
	}
}
