import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
    		output.append("Case " + i + ": ");
    		String encode = br.readLine();
    		int len = encode.length();
    		for(int j = 0; j < len; ++j) {
    		    if(Character.isUpperCase(encode.charAt(j))) {
    		        int frequency = 0, k = j + 1;
    		        do {
    		            frequency = 10 * frequency + encode.charAt(k++) - '0';
    		        } while(k < len && Character.isDigit(encode.charAt(k)));
    		        while(frequency-- > 0)
    		            output.append(encode.charAt(j));
    		        j = k - 1;
    		    }
    		}
    		output.append("\n");
    	}
        System.out.print(output);
	}
}
