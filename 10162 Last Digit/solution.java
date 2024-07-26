import java.io.*;

public class Main {
    static int[] lastDigit = {
        0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 
        7, 8, 4, 7, 3, 8, 4, 1, 5, 4,
    };
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String N;
    	StringBuilder output = new StringBuilder();
    	while((N = br.readLine()).charAt(0) != '0') {
	        int dividend = 0, len = N.length();
	        for(int i = 0; i < len - 1; ++i)
	            dividend = (10 * dividend + N.charAt(i) - '0') % 20;
	        dividend = 10 * dividend + N.charAt(len - 1) - '0';
	        output.append((dividend / 20 * 4 + lastDigit[dividend % 20]) % 10 + "\n");
    	}
	    System.out.print(output);
	}
}
