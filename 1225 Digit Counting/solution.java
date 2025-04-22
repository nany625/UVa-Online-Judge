import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int N = (int)st.nval;
            int[] digitCounts = new int[10];
            do {
                solve(digitCounts, N);
            } while(--N > 0);
            for(int i = 0; i < 9; ++i)
                output.append(digitCounts[i]).append(' ');
            output.append(digitCounts[9]).append('\n');
        }
        System.out.print(output);
    }
    
    static void solve(int[] array, int n) {
        do {
            ++array[n % 10];
            n /= 10;
        } while(n > 0);
    }
}
