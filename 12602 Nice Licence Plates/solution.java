import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(N-- > 0) {
		    String s = br.readLine();
		    output.append(Math.abs(26 * 26 * (s.charAt(0) - 'A') + 26 * (s.charAt(1) - 'A') + (s.charAt(2) - 'A') - Integer.parseInt(s.substring(4))) <= 100 ? "nice\n" : "not nice\n");
		}
		System.out.print(output);
	}
}
