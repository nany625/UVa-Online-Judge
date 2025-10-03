import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder output = new StringBuilder();
		while((line = br.readLine()) != null) {
			String[] tokens = line.split("\\s+");
			for(int i = 0; i < tokens.length; ++i) {
				if(i > 0)
					output.append(' ');
				for(int j = tokens[i].length() - 1; j >= 0; --j)
					output.append(tokens[i].charAt(j));
			}
			output.append('\n');
		}
		System.out.print(output);
	}
}
