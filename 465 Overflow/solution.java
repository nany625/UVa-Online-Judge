import java.io.*;
import java.math.*;

public class Main {
    static BigInteger limit = new BigInteger("2147483648");
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
            if(!first.divide(limit).equals(BigInteger.ZERO))
                output.append("first number too big\n");
            if(!second.divide(limit).equals(BigInteger.ZERO))
                output.append("second number too big\n");
            if(!ans.divide(limit).equals(BigInteger.ZERO))
                output.append("result too big\n");
        }
        System.out.print(output);
    }
}
