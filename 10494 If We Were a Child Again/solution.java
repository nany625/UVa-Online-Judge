import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null) {
		    String[] tokens = s.split("\\s+");
		    if(tokens[1].charAt(0) == '/')
		        output.append(new BigInteger(tokens[0]).divide(new BigInteger(tokens[2]))).append('\n');
		    else if(tokens[1].charAt(0) == '%')
		        output.append(new BigInteger(tokens[0]).mod(new BigInteger(tokens[2]))).append('\n');
		}
		System.out.print(output);
	}
}
