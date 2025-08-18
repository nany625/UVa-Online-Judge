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
            int n = (int)Math.pow(10, (int)st.nval);
            st.nextToken();
            long k = (long)st.nval;
            while(k >= n)
                k /= 10;
            long max = k;
            Set<Long> display = new HashSet<>();
            do {
                display.add(k);
                k *= k;
                while(k >= n)
                    k /= 10;
                max = Math.max(max, k);
            } while(!display.contains(k));
            output.append(max).append('\n');
        }
        System.out.print(output);
	}
}
