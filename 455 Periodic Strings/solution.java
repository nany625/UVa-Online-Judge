import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            br.readLine();
	        String s = br.readLine();
            int len = s.length(), i = 1, length = 0;
	        short[] LPS = new short[len];
	        while(i < len) {
	            if(s.charAt(i) == s.charAt(length))
	                LPS[i++] = (short)(++length);
	            else {
	                if(length != 0)
	                    length = LPS[length - 1];
	                else
	                    LPS[i++] = 0;
	            }
	        }
			output.append(len % (len - LPS[len - 1]) == 0 ? len - LPS[len - 1] : len).append('\n');
			if(N > 0)
				output.append('\n');
        }
        System.out.print(output);
	}
}
