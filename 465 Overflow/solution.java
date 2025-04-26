import java.io.*;
import java.math.*;

public class Main {
    static BigInteger limit = new BigInteger("2147483647");
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        String buffer;
        StringBuilder output = new StringBuilder();
        while((buffer = br.readLine()) != null) {
            output.append(buffer).append('\n');
            String[] tokens = buffer.split("\\s+");
            BigInteger first = new BigInteger(tokens[0]);
            BigInteger second = new BigInteger(tokens[2]);
            BigInteger ans;
            if(tokens[1].charAt(0) == '+')
                ans = first.add(second);
            else
                ans = first.multiply(second);
            if(first.compareTo(limit) > 0)
                output.append("first number too big\n");
            if(second.compareTo(limit) > 0)
                output.append("second number too big\n");
            if(ans.compareTo(limit) > 0)
                output.append("result too big\n");
        }
        System.out.print(output);
    }
}
