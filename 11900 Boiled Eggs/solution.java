import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
		    int n = (int)st.nval;
		    st.nextToken();
		    int P = (int)st.nval;
		    st.nextToken();
		    int Q = (int)st.nval;
		    int[] weights = new int[n];
		    for(int j = 0; j < n; ++j) {
		        st.nextToken();
		        weights[j] = (int)st.nval;
		    }
            Arrays.sort(weights);
            int total = 0, count = 0;
            n = Math.min(n, P);
            while(count < n) {
                if(total + weights[count] > Q)
                    break;
                total += weights[count++];
            }
            output.append("Case ").append(i).append(": ").append(count).append('\n');
        }
		System.out.print(output);
	}
}
