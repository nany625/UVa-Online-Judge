import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            output.append(new BigInteger(st.nextToken()).subtract(new BigInteger(st.nextToken()))).append('\n');
        }
        System.out.print(output);
    }
}
