import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            int x = Integer.parseInt(line);
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = st.countTokens();
            long result = 0;
            for(int i = 0; i < n - 1; ++i)
                result = result * x + Long.parseLong(st.nextToken()) * (n - 1 - i);
            output.append(result).append('\n');
        }
        System.out.print(output);
	}
}
