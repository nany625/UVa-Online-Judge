import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder output = new StringBuilder();
		while((line = br.readLine()) != null) {
		    String[] tokens = line.split("\\s+");
		    int max = Integer.parseInt(tokens[0]), curr = max;
		    for(int i = 1; i < tokens.length; ++i) {
		        int temp = Integer.parseInt(tokens[i]);
		        curr = Math.max(temp, curr + temp);
		        max = Math.max(max, curr);
		    }
		    output.append(max >= 0 ? max : 0).append('\n');
		}
        System.out.print(output);
	}
}
