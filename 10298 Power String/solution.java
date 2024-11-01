import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        String s;
        StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_WORD && (s = st.sval).charAt(0) != '.') {
	        int i = 1, length = 0;
	        int[] lps = new int[s.length()];
	        while(i < s.length()) {
	            if(s.charAt(i) == s.charAt(length))
	                lps[i++] = ++length;
	            else {
	                if(length != 0)
	                    length = lps[length - 1];
	                else
	                    lps[i++] = 0;
	            }
	        }
			output.append((s.length() % (s.length() - lps[s.length() - 1]) == 0 ? s.length() / (s.length() - lps[s.length() - 1]) : 1)).append('\n');
        }
	    System.out.print(output);
	}
}
