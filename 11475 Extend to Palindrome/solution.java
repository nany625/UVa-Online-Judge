import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
	        String s = st.sval;
	        StringBuilder concat = new StringBuilder(s).reverse().append("#" + s);
            int len = s.length(), i = 1, length = 0;
	        int[] lps = new int[(len << 1) + 1];
	        while(i < (len << 1) + 1) {
	            if(concat.charAt(i) == concat.charAt(length))
	                lps[i++] = ++length;
	            else {
	                if(length != 0)
	                    length = lps[length - 1];
	                else
	                    lps[i++] = 0;
	            }
	        }
			output.append(s);
			for(int j = len - lps[(len << 1)] - 1; j >= 0; --j)
			    output.append(s.charAt(j));
			output.append('\n');
        }
        System.out.print(output);
	}
}
