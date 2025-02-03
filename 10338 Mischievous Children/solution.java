import java.io.*;
import java.util.*;

public class Main {
    static long[] fac = new long[21];
	public static void main(String[] args) throws IOException {
	    fac[0] = fac[1] = 1;
	    for(int i = 2; i < 21; ++i)
            fac[i] = fac[i - 1] * i;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int dataSets = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= dataSets; ++i) {
		    st.nextToken();
            String s = st.sval;
            int[] count = new int[26];
            for(int j = 0; j < s.length(); ++j)
                ++count[s.charAt(j) - 'A'];
            long ans = fac[s.length()];
            for(int j = 0; j < 26; ++j)
                ans /= fac[count[j]];
            output.append("Data set ").append(i).append(": ").append(ans).append('\n');
        }
		System.out.print(output);
	}
}
