import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    double temp = Math.log(n) / Math.log(2);
		    output.append((int)temp + n - 2 + (temp != (int)temp ? 1 : 0)).append('\n');
		}
		System.out.print(output);
	}
}
