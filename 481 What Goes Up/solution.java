import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Integer> sequence = new ArrayList<>();
        StreamTokenizer st = new StreamTokenizer(System.in);
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    sequence.add((int)st.nval);
		ArrayList<DP> dp = new ArrayList<>();
		int size = sequence.size(), lisSize = 0;
		int[] predecessor = new int[size];
		for(int i = 0; i < size; ++i) {
		    int pos = binarySearch(dp, lisSize, sequence.get(i));
		    if(pos == lisSize) {
		        dp.add(new DP(i, sequence.get(i)));
		        ++lisSize;
		    } else 
		        dp.get(pos).lis = sequence.get(dp.get(pos).lastIndex = i);
		    predecessor[i] = pos > 0 ? dp.get(pos - 1).lastIndex : -1;
		}
		int[] ans = new int[lisSize];
		int i = dp.get(lisSize - 1).lastIndex;
		for(int j = lisSize - 1; j >= 0; --j) {
		    ans[j] = sequence.get(i);
		    i = predecessor[i];
		}
		StringBuilder output = new StringBuilder().append(lisSize).append("\n-\n");
		for(Integer j : ans)
		    output.append(j).append('\n');
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<DP> arrayList, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(arrayList.get(mid).lis < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

class DP {
    int lastIndex, lis;
    DP(int lastIndex, int lis) {
        this.lastIndex = lastIndex;
        this.lis = lis;
    }
}
