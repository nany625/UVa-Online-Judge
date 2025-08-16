import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            Map<Integer, Integer> snowflake = new HashMap<>();
            int ans = 0, top = 1;
            for(int i = 1; i <= n; ++i) {
                st.nextToken();
                int num = (int)st.nval;
                if(snowflake.containsKey(num)) {
                    if(top <= snowflake.get(num)) {
                        ans = Math.max(ans, i - top);
                        top = snowflake.get(num) + 1;
                    }
                    snowflake.replace(num, i);
                } else
                    snowflake.put(num, i);
            }
            output.append(Math.max(ans, n + 1 - top)).append('\n');
        }
        System.out.print(output);
	}
}
