import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int[] locations = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                locations[i] = (int)st.nval;
            }
            Arrays.sort(locations);
            boolean possible = true;
            for(int i = 1; i < n && possible; ++i)
                possible = locations[i] - locations[i - 1] <= 200;
            output.append(possible && locations[n - 1] >= 1322 ? "POSSIBLE\n" : "IMPOSSIBLE\n");
        }
		System.out.print(output);
	}
}
