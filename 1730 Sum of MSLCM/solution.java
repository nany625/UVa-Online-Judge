import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int limit = (int)Math.sqrt(N);
            long ans = -1;
            long[] quotients = new long[limit + 1];
            for(int i = 1; i <= limit; ++i) {
                quotients[i] = N / i;
                ans += i * quotients[i];
            }
            for(int i = 1; i < limit; ++i)
                ans += i * (quotients[i] + quotients[i + 1] + 1) * (quotients[i] - quotients[i + 1]) >> 1;
            if(limit != quotients[limit])
                ans += limit * (quotients[limit] + N / (limit + 1) + 1) * (quotients[limit] - N / (limit + 1)) >> 1;
            output.append(ans).append('\n');
        }
		System.out.print(output);
	}
}
