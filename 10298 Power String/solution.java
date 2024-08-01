import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        String s;
        StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_WORD && (s = st.sval).charAt(0) != '.') {
	        int len = s.length(), i = 1, length = 0;
	        int[] lps = new int[len];
	        while(i < len) {
	            if(s.charAt(i) == s.charAt(length))
	                lps[i++] = ++length;
	            else {
	                if(length != 0)
	                    length = lps[length - 1];
	                else
	                    lps[i++] = 0;
	            }
	        }
			output.append((len % (len - lps[len - 1]) == 0 ? len / (len - lps[len - 1]) : 1) + "\n");
        }
	    System.out.print(output);
	}
}
