import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER)
            output.append((int)st.nval * 3 / 2 + "\n");
        System.out.print(output);
	}
}
