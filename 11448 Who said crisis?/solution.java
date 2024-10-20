import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            String[] tokens = br.readLine().split("\\s+");
            output.append(new BigInteger(tokens[0]).subtract(new BigInteger(tokens[1]))).append('\n');
        }
        System.out.print(output);
    }
}
