import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(N-- > 0) {
		    String buffer = br.readLine();
		    String[] tokens = buffer.split("\\s+");
		    if(tokens.length == 2 && Integer.parseInt(tokens[0]) >= 0 && Integer.parseInt(tokens[1]) >= 0) {
		        int r1 = Integer.parseInt(tokens[0]), r2 = Integer.parseInt(tokens[1]);
		        output.append(String.format("%.4f\n", 2 * r1 * r2 * Math.PI));
		    }
		    else if(tokens.length == 1 && Integer.parseInt(tokens[0]) >= 0) {
		        int t = Integer.parseInt(tokens[0]);
		        output.append(String.format("%.4f\n", t * t * Math.PI / 8));
		    }
		    else
		        output.append("Impossible\n");
		}
		System.out.print(output);
	}
}
