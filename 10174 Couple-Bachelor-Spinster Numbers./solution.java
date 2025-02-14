import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null && !s.isEmpty()) {
			String[] tokens = s.split("\\s+");
			int n1 = Integer.parseInt(tokens[0]);
			if(tokens.length == 1) {
			    if((n1 & 3) == 2)
			        output.append("Bachelor Number.\n");
			    else if((n1 & 1) == 1)
			        output.append(Math.abs((n1 >> 1) + 1)).append(' ').append(Math.abs(n1 >> 1)).append('\n');
			    else
			        output.append(Math.abs((n1 >> 2) + 1)).append(' ').append(Math.abs((n1 >> 2) - 1)).append('\n');
			} else {
			    int n2 = Integer.parseInt(tokens[1]);
			    while((n1 & 3) != 2)
                    ++n1;
                while((n2 & 3) != 2)
                    --n2;
                output.append(((n2 - n1) >> 2) + 1).append('\n');
			}
		}
		System.out.print(output);
	}
}
