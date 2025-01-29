import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null && !s.isEmpty()) {
		    if(s.equals("0") || s.equals("1"))
		        output.append("Not an Automorphic number.\n");
		    else {
		        String num = new BigInteger(s).pow(2).toString();
    		    if(num.length() < s.length())
    		        output.append("Not an Automorphic number.\n");
    		    else if(num.substring(num.length() - s.length()).equals(s))
    		        output.append("Automorphic number of ").append(s.length()).append("-digit.\n");
    		    else
    		        output.append("Not an Automorphic number.\n");
		    }
		}
		System.out.print(output);
	}
}
