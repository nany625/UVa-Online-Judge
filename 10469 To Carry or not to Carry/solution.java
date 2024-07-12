import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int num1 = (int)st.nval;
		    st.nextToken();
		    output.append((num1 ^ (int)st.nval) + "\n");
		}
		System.out.print(output);
	}
}
