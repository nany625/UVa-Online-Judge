import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null) {
		    output.append("Case " + (++cases) + ":\n");
		    int len = s.length();
		    int[] groups = new int[len];
		    for(int i = 1; i < len; ++i)
                groups[i] = groups[i - 1] + (s.charAt(i) != s.charAt(i - 1) ? 1 : 0);
            st.nextToken();
            int n = (int)st.nval;
            while(n-- > 0) {
                st.nextToken();
                int i = (int)st.nval;
                st.nextToken();
                int j = (int)st.nval;
                output.append(groups[i] == groups[j] ? "Yes\n" : "No\n");
            }
		}
		System.out.print(output);
	}
}
