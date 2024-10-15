// #解法一
import java.io.*;

public class Main {
    static int[] lastDigit = {
        0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 
        7, 8, 4, 7, 3, 8, 4, 1, 5, 4
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
	        output.append((dividend / 20 * 4 + lastDigit[dividend % 20]) % 10).append('\n');
    	}
	    System.out.print(output);
	}
}

// #解法二
import java.io.*;

public class Main {
    static char lastDigit[] = {
        '0', '1', '5', '2', '8', '3', '9', '2', '8', '7',
        '7', '8', '4', '7', '3', '8', '4', '1', '5', '4',
        '4', '5', '9', '6', '2', '7', '3', '6', '2', '1',
        '1', '2', '8', '1', '7', '2', '8', '5', '9', '8',
        '8', '9', '3', '0', '6', '1', '7', '0', '6', '5',
        '5', '6', '2', '5', '1', '6', '2', '9', '3', '2',
        '2', '3', '7', '4', '0', '5', '1', '4', '0', '9',
        '9', '0', '6', '9', '5', '0', '6', '3', '7', '6',
        '6', '7', '1', '8', '4', '9', '5', '8', '4', '3',
        '3', '4', '0', '3', '9', '4', '0', '7', '1', '0'
    };
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String N;
    	StringBuilder output = new StringBuilder();
    	while((N = br.readLine()).charAt(0) != '0') {
	        int len = N.length();
	        if(len == 1)
	            output.append(lastDigit[N.charAt(0) - '0']).append('\n');
	        else
	            output.append(lastDigit[(N.charAt(len - 2) - '0') * 10 + N.charAt(len - 1) - '0']).append('\n');
    	}
	    System.out.print(output);
	}
}
