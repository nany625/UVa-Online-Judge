import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int pos = (int)st.nval;
		    st.nextToken();
		    int num1 = (int)st.nval;
		    st.nextToken();
		    int num2 = (int)st.nval;
		    st.nextToken();
		    int num3 = (int)st.nval;
		    if(pos == 0 && num1 == 0 && num2 == 0 && num3 == 0)
		        break;
		    output.append(1080 + 9 * ((pos - num1 + 40) % 40 + (num2 - num1 + 40) % 40 + (num2 - num3 + 40) % 40) + "\n");
		}
		System.out.print(output);
	}
}
