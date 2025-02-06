import java.io.*;

public class Main {
    static int[] fac = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int ans = fac[(int)st.nval];
            st.nextToken();
            int k = (int)st.nval;
            while(k-- > 0) {
                st.nextToken();
                ans /= fac[(int)st.nval];
            }
            output.append(ans).append('\n');
        }
        System.out.print(output);
    }
}
