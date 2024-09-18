import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            ArrayList<Integer> cost = new ArrayList<>();
            int L;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (L = (int)st.nval) != 0)
                cost.add(L);
            cost.sort(Comparator.reverseOrder());
            int total = 0, size = cost.size();
        	for(int i = 0; i < size && total <= 5000000; ++i)
        		total += (int)Math.pow(cost.get(i), i + 1) << 1;
            output.append(total <= 5000000 ? total : "Too expensive").append('\n');
        }
        System.out.print(output);
	}
}
