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
    	    output.append((tokenSum(number, 0, 4) + tokenSum(number, 5, 9) + tokenSum(number, 10, 14) + tokenSum(number, 15, 19)) % 10 == 0 ? "Valid\n" : "Invalid\n");
        }
        System.out.print(output);
	}
	
	static int tokenSum(String number, int first, int last) {
	    int result = 0;
	    for(int i = first; i < last; ++i) {
            int digit = number.charAt(i) - '0';
    	    if((i % 5 & 1) == 0)
    	        result += (digit << 1) / 10 + (digit << 1) % 10;
    	    else
    	        result += digit;
        }
        return result;
	}
}
