import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int remainder = 0;
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            int len = line.length();
    	    for(int i = 0; i < len; ++i) {
    	        if(line.charAt(i) != '#')
    	            remainder = (2 * remainder + line.charAt(i) - '0') % 131071;
    	        else {
    	            output.append(remainder == 0 ? "YES\n" : "NO\n");
    	            remainder = 0;
    	        }
    	    }
        }
        System.out.print(output);
	}
}
