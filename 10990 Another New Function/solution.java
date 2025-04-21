import java.io.*;

public class Main {
    static int MAX_NUM = 2000000;
    static int[] phi = new int[MAX_NUM + 1], sodf = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    for(int n = 2; n <= MAX_NUM; ++n)
            phi[n] = n;
        eratosthenesSieve();
        for(int n = 2; n <= MAX_NUM; ++n)
            sodf[n] = sodf[phi[n]] + 1;
        for(int n = 3; n <= MAX_NUM; ++n)
            sodf[n] += sodf[n - 1];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int m = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            output.append(sodf[n] - sodf[m - 1]).append('\n');
        }
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
