import java.io.*;
import java.math.*;

public class Main {
    static int MOD = 1000000007;
    static int inv2 = MOD + 1 >> 1;
    static int inv6 = 166666668;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		int N;
		for(int i = 1; i <= t; ++i) {
		    st.nextToken();
		    long n = (long)st.nval;
		    long startRow = ((n >> 1) + 1) % MOD;
            long rows = (n - startRow + 1) % MOD;
            long cols = (rows + ((n & 1) == 0 ? 1 : 0)) % MOD;
            long topLeft = startRow * (startRow - 1) % MOD * inv2 % MOD;
            ++topLeft;
            long topRight = (topLeft + startRow - 1) % MOD;
            long sum1 = (topLeft + topRight) * cols % MOD * inv2 % MOD;
            long part1 = rows * sum1 % MOD;
            long part2 = rows * (rows - 1) % MOD * inv2 % MOD * startRow % MOD;
            long part3 = (rows - 1) * rows % MOD * (rows + 1) % MOD * inv6 % MOD;
            long ans = (part1 + (part2 + part3) % MOD * cols % MOD) % MOD;
            output.append("Case #").append(i).append(": ").append(ans).append('\n');
		}
		System.out.print(output);
	}
}
