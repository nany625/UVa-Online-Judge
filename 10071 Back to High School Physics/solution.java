import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int v = (int)st.nval;
            st.nextToken();
            output.append(v * (int)st.nval << 1).append('\n');
		}
        System.out.print(output);
	}
}
