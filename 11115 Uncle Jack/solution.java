import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		StringBuilder output = new StringBuilder();
		while((line = br.readLine()) != null) {
		    StringTokenizer st = new StringTokenizer(line);
		    String N = st.nextToken();
		    if(N.charAt(0) == '0')
		        break;
		    output.append(new BigInteger(N).pow(Integer.parseInt(st.nextToken()))).append('\n');
		}
		System.out.print(output);
	}
}
