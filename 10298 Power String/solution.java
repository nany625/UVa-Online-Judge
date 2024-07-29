import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        String s;
        StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_WORD && (s = st.sval).charAt(0) != '.') {
	        int len = s.length(), i = 1, length = 0;
	        int[] LPS = new int[len];
	        while(i < len) {
	            if(s.charAt(i) == s.charAt(length))
	                LPS[i++] = ++length;
	            else {
	                if(length != 0)
	                    length = LPS[length - 1];
	                else
	                    LPS[i++] = 0;
	            }
	        }
			output.append((len % (len - LPS[len - 1]) == 0 ? len / (len - LPS[len - 1]) : 1) + "\n");
        }
	    System.out.print(output);
	}
}
