import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		br.readLine();
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    ArrayList<DP> dp = new ArrayList<>();
		    String line;
		    while((line = br.readLine()) != null && !line.isEmpty())
		        dp.add(new DP(Integer.parseInt(line)));
		    ArrayList<Integer> lis = new ArrayList<>();
		    int lisSize = 0;
		    for(int i = dp.size() - 1; i >= 0; --i) {
		        dp.get(i).length = binarySearch(lis, lisSize, dp.get(i).altitude);
		        if(dp.get(i).length == lisSize) {
		            lis.add(dp.get(i).altitude);
		            ++lisSize;
		        } else
		            lis.set(dp.get(i).length, dp.get(i).altitude);
		    }
		    output.append("Max hits: ").append(lisSize).append('\n');
		    int i = lisSize - 1;
		    for(int j = 0; i >= 0; ++j) {
		        if(dp.get(j).length == i) {
		            output.append(dp.get(j).altitude).append('\n');
		            --i;
		        }
		    }
		    if(cases > 0)
		        output.append('\n');
		}
        System.out.print(output);
	}
	
	static int binarySearch(ArrayList<Integer> arrayList, int size, int key) {
        int left = 0, right = size - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(arrayList.get(mid) > key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

class DP {
    int altitude, length;
    DP(int altitude) {
        this.altitude = altitude;
    }
}
