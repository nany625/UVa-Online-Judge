import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int x = (int)st.nval;
            String[] a = br.readLine().split("\\s+");
            long result = 0;
            int len = a.length - 1;
            for(int i = 0; i < len; ++i)
                result = result * x + Long.parseLong(a[i]) * (len - i);
            output.append(result).append('\n');
        }
        System.out.print(output);
	}
}
