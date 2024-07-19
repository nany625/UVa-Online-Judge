import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            String number = br.readLine();
            int sum = 0;
            for(int i = 0; i < 19; ++i) {
        	    if((i - 4) % 5 == 0)
        	        continue;
                int digit = number.charAt(i) - '0';
    	        if(i % 5 % 4 == 0 || i % 5 % 4 == 2)
    	            sum += (2 * digit) / 10 + (2 * digit) % 10;
    	        else
    	            sum += digit;
    	    }
    	    output.append(sum % 10 == 0 ? "Valid\n" : "Invalid\n");
        }
        System.out.print(output);
	}
}
