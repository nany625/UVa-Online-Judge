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
            int len = s.length();
			boolean found = false;
    		for(int k = 1; k <= len / 2 && !found; ++k) {
				if(len % k == 0) {
    				int i = k;
					while(i < len && s.substring(0, k).equals(s.substring(i, i + k)))
    					i += k;
    				if(i >= len) {
						output.append(k + "\n");
    					found = true;
					}
				}
			}
			if(!found)
			    output.append(len + "\n");
			firstCase = false;
        }
        System.out.print(output);
	}
}
