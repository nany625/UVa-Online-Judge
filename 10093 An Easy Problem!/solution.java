import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String R;
        StringBuilder output = new StringBuilder();
        while((R = br.readLine()) != null) {
            int max = 1, sumOfDigits = 0, len = R.length();
            for(int i = 0; i < len; ++i) {
    			int digit = 0;
    			if(Character.isDigit(R.charAt(i)))
    				digit = R.charAt(i) - '0';
    			else if(Character.isUpperCase(R.charAt(i)))
    				digit = R.charAt(i) - 'A' + 10;
    			else if(Character.isLowerCase(R.charAt(i)))
    				digit = R.charAt(i) - 'a' + 36;
    			sumOfDigits += digit;
    			max = Math.max(max, digit);
    		}
    		int N = max + 1;
    		while(N <= 62 && sumOfDigits % (N - 1) != 0)
    		    ++N;
    		if(N <= 62)
    		    output.append(N + "\n");
    		else
    			output.append("such number is impossible!\n");
		}
        System.out.print(output);
	}
}
