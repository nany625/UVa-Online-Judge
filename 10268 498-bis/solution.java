import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int x = (int)st.nval;
            String line = br.readLine();
            StringTokenizer strtok = new StringTokenizer(line);
            int n = strtok.countTokens();
            long result = 0;
            for(int i = 0; i < n - 1; ++i)
                result = result * x + Long.parseLong(strtok.nextToken()) * (n - 1 - i);
            output.append(result).append('\n');
        }
        System.out.print(output);
	}
}
