import java.io.*;

public class Main {
    static int MAX_NUM = 4000000;
    static int[] phi = new int[MAX_NUM + 1];
    static long[] ans = new long[MAX_NUM + 1];
    public static void main(String[] args) throws IOException {
        for(int n = 2; n <= MAX_NUM; ++n)
            phi[n] = n;
        eratosthenesSieve();
        for(int n = 2; n <= MAX_NUM; ++n) {
            for(int i = n << 1; i <= MAX_NUM; i += n)
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
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(phi[n] == n) {
                for(int i = n; i <= MAX_NUM; i += n)
                    phi[i] -= phi[i] / n;
            }
        }
    }
}
