import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(t-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            int[] p = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                p[i] = (int)st.nval;
            }
            Arrays.sort(p);
            int save = 0;
            for(int i = n % 3; i < n; i += 3)
                save += p[i];
            output.append(save).append('\n');
        }
        System.out.print(output);
	}
}
