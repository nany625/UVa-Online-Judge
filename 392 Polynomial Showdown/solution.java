import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int[] coefficients = new int[9];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    coefficients[0] = (int)st.nval;
		    for(int i = 1; i < 9; ++i) {
		        st.nextToken();
		        coefficients[i] = (int)st.nval;
		    }
		    boolean leadingZero = true;
		    for(int i = 0; i < 9; ++i) {
		        if(coefficients[i] != 0) {
    				if(!leadingZero) {
    					if(coefficients[i] < 0)
    						output.append(" - ");
    					else
    						output.append(" + ");
    				} else {
    					if(coefficients[i] < 0)
    						output.append('-');
    				}
    				if(i == 8)
    					output.append(Math.abs(coefficients[i]));
    				else if(i == 7) {
    					if(Math.abs(coefficients[i]) > 1)
    						output.append(Math.abs(coefficients[i]));
    					output.append('x');
    				} else {
    					if(Math.abs(coefficients[i]) > 1)
    						output.append(Math.abs(coefficients[i]));
    					output.append("x^" + (8 - i));
    				}
    				leadingZero = false;
    			}
		    }
		    if(leadingZero)
		        output.append('0');
		    output.append('\n');
		}
		System.out.print(output);
	}
}
