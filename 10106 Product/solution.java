import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String X;
            while((X = br.readLine()) != null) {
                System.out.println(new BigInteger(X).multiply(new BigInteger(new String(br.readLine()))));
            }
	    } catch(IOException e) {}
	}
}
