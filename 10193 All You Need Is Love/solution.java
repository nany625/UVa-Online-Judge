import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= N; ++i) {
            String S1 = br.readLine(), S2 = br.readLine();
            int num1 = 0, num2 = 0, len = S1.length();
            for(int j = 0; j < len; ++j)
                num1 = 2 * num1 + S1.charAt(j) - '0';
            len = S2.length();
            for(int j = 0; j < len; ++j)
                num2 = 2 * num2 + S2.charAt(j) - '0';
            output.append("Pair #" + i + ": " + (GCD(num1, num2) > 1 ? "All you need is love" : "Love is not all you need") + "!\n");
        }
        System.out.print(output);
	}
	
	static int GCD(int i, int j) {
        return j == 0 ? i : GCD(j, i % j);
    }
}
