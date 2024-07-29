import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            if(!firstCase)
				output.append("\n");
            br.readLine();
	        String s = br.readLine();
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
			output.append((len % (len - LPS[len - 1]) == 0 ? len - LPS[len - 1] : len) + "\n");
			firstCase = false;
        }
        System.out.print(output);
	}
}
