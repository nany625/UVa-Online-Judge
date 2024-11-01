import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int remainder = 0;
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
    	    for(int i = 0; i < line.length(); ++i) {
    	        if(line.charAt(i) != '#')
    	            remainder = ((remainder << 1) + line.charAt(i) - '0') % 131071;
    	        else {
    	            output.append(remainder == 0 ? "YES\n" : "NO\n");
    	            remainder = 0;
    	        }
    	    }
        }
        System.out.print(output);
	}
}
