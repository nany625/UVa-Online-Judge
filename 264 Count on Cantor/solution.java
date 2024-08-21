import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int number = (int)st.nval;
            int i = (int)Math.ceil((-1 + Math.sqrt(1 + 8 * number)) / 2);
            int a = i + 1 - number + (i - 1) * i / 2;
            int b = number - (i - 1) * i / 2;
            output.append("TERM ").append(number).append(" IS ").append(i % 2 == 1 ? a : b).append('/').append(i % 2 == 1 ? b : a).append('\n');
		}
        System.out.print(output);
	}
}
