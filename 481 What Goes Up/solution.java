import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Integer> sequence = new ArrayList<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    sequence.add((int)st.nval);
		ArrayList<DP> dp = new ArrayList<>();
		int[] predecessor = new int[sequence.size()];
		for(int i = 0; i < sequence.size(); ++i) {
		    int pos = binarySearch(dp, sequence.get(i));
		    if(pos == dp.size())
		        dp.add(new DP(i, sequence.get(i)));
		    else 
		        dp.get(pos).lis = sequence.get(dp.get(pos).lastIndex = i);
		    predecessor[i] = pos > 0 ? dp.get(pos - 1).lastIndex : -1;
		}
		int[] ans = new int[dp.size()];
		int i = dp.get(dp.size() - 1).lastIndex;
		for(int j = dp.size() - 1; j >= 0; --j) {
		    ans[j] = sequence.get(i);
		    i = predecessor[i];
		}
		StringBuilder output = new StringBuilder().append(lisSize).append("\n-\n");
		for(Integer j : ans)
		    output.append(j).append('\n');
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<DP> arrayList, int key) {
        int left = 0, right = arrayList.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
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
