import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int number = (int)st.nval;
            int i = (int)Math.ceil((-1 + Math.sqrt(1 + (number << 3))) / 2);
            int a = i + 1 - number + ((i - 1) * i >> 1);
            int b = number - ((i - 1) * i >> 1);
            output.append("TERM ").append(number).append(" IS ").append((i & 1) == 1 ? a : b).append('/').append((i & 1) == 1 ? b : a).append('\n');
		}
        System.out.print(output);
	}
}
