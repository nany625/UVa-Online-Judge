import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    st.nextToken();
		    int prev = (int)st.nval;
		    ArrayList<Integer> indices = new ArrayList<>();
		    for(int i = 1; i < n; ++i) {
		        st.nextToken();
		        int curr = (int)st.nval;
		        if(prev > curr)
		            indices.add(i);
		        prev = curr;
		    }
		    if(indices.size() <= 1)
                output.append(n).append('\n');
            else {
                int max = indices.get(1);
                for(int i = 2; i < indices.size(); ++i)
                    max = Math.max(max, indices.get(i) - indices.get(i - 2));
                output.append(Math.max(max, n - indices.get(indices.size() - 2))).append('\n');
            }
		}
		System.out.print(output);
	}
}
