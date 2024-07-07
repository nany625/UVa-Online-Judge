import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            double a = st.nval;
            output.append(String.format("%.3f %.3f %.3f\n", a * a * (Math.PI / 3 + 1 - Math.sqrt(3)), 4 * a * a * (Math.PI / 12 - 1 + Math.sqrt(3) / 2), 4 * a * a * (-Math.PI / 6 + 1 - Math.sqrt(3) / 4)));
        }
        System.out.print(output);
	}
}
