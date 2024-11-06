import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N;
		StringBuilder output = new StringBuilder();
		while((N = br.readLine()) != null && N.charAt(0) != '0') {
		    int sum = 0;
		    for(int i = 0; i < N.length(); ++i) {
    	        if((i & 1) == 1)
    	            sum -= N.charAt(i) - '0';
    	        else
    	            sum += N.charAt(i) - '0';
    	    }
    	    output.append(N).append(sum % 11 == 0 ? " is a multiple of 11.\n" : " is not a multiple of 11.\n");
		}
		System.out.print(output);
	}
}
