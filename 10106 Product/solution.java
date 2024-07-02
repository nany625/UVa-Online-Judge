import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String X;
        StringBuilder output = new StringBuilder();
        while((X = br.readLine()) != null) {
            output.append(new BigInteger(X).multiply(new BigInteger(new String(br.readLine()))) + "\n");
        }
        System.out.print(output);
	}
}
