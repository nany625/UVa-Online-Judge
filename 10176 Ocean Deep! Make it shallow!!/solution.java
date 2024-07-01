import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int remainder = 0;
            String line;
            while((line = br.readLine()) != null) {
                int len = line.length();
    		    for(int i = 0; i < len; ++i) {
    		        if(line.charAt(i) != '#')
    		            remainder = (2 * remainder + line.charAt(i) - '0') % 131071;
    		        else {
    		            System.out.println(remainder == 0 ? "YES" : "NO");
    		            remainder = 0;
    		        }
    		    }
            }
	    } catch(IOException e) {}
	}
}
