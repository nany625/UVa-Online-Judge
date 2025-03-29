import java.io.*;

public class Main {
    static int MAXN = 4000000;
    static int[] phi = new int[MAXN + 1];
    static long[] ans = new long[MAXN + 1];
    public static void main(String[] args) throws IOException {
        for(int n = 2; n <= MAXN; ++n)
            phi[n] = n;
        eratosthenesSieve();
        for(int n = 2; n <= MAXN; ++n) {
            for(int i = n << 1; i <= MAXN; i += n)
                ans[i] += n * phi[i / n];
            ans[n] += ans[n - 1] + phi[n];
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
		    output.append(ans[N]).append('\n');
        System.out.print(output);
    }
    
    static void eratosthenesSieve() {
        for(int n = 2; n <= MAXN; ++n) {
            if(phi[n] == n) {
                for(int i = n; i <= MAXN; i += n)
                    phi[i] -= phi[i] / n;
            }
        }
    }
}
