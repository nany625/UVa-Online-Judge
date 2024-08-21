import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
	        int num1 = (int)st.nval;
	        st.nextToken();
	        int num2 = (int)st.nval;
	        if(num1 == 0 && num2 == 0)
	            break;
	        int count = 0, carry = 0;
	        while((num1 > 0 && num2 > 0) || (num1 > 0 && carry > 0) || (num2 > 0 && carry > 0)) {
	            carry = (num1 % 10 + num2 % 10 + carry) / 10;
    	        count += carry;
    	        num1 /= 10;
    	        num2 /= 10;
	        }
	        if(count == 0)
    	        output.append("No carry operation.\n");
    	    else
    	        output.append(count).append(" carry operation").append(count > 1 ? "s.\n" : ".\n");
	    }
        System.out.print(output);
	}
}
