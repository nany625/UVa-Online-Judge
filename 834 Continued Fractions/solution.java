import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int numerator = (int)st.nval;
		    st.nextToken();
		    int denominator = (int)st.nval, count = 0;
		    do {
		        if(count == 0)
		            output.append('[').append(numerator / denominator);
		        else if(count == 1)
		            output.append(';').append(numerator / denominator);
		        else
		            output.append(',').append(numerator / denominator);
		        int temp = numerator %= denominator;
		        numerator = denominator;
		        denominator = temp;
		        ++count;
		    } while(denominator > 0);
		    output.append("]\n");
		}
		System.out.print(output);
	}
}
