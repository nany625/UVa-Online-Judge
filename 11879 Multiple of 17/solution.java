import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n;
        StringBuilder output = new StringBuilder();
        while((n = br.readLine()) != null && n.charAt(0) != '0') {
            int len = n.length(), dividend = 0;
            for(int i = 0; i < len; ++i)
                dividend = (10 * dividend + n.charAt(i) - '0') % 17;
            output.append(dividend == 0 ? 1 : 0).append('\n');
        }
        System.out.print(output);
	}
}
