import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int M = (int)st.nval;
            st.nextToken();
	        output.append(M * (int)st.nval - 1 + "\n");
        }
        System.out.print(output);
	}
}
