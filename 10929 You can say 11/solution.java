import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N;
		StringBuilder output = new StringBuilder();
		while((N = br.readLine()) != null && !N.equals("0")) {
		    int sum = 0, len = N.length();
		    for(int i = 0; i < len; ++i) {
    	        if(i % 2 == 0)
    	            sum += N.charAt(i) - '0';
    	        else
    	            sum -= N.charAt(i) - '0';
    	    }
    	    output.append(N + " is " + (sum % 11 == 0 ? "" : "not ") + "a multiple of 11.\n");
		}
		System.out.print(output);
	}
}
