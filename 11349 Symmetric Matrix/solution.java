import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            st.nextToken();
            st.nextToken();
            int n = (int)st.nval;
            long[][] M = new long[n][n];
            boolean isSymmetric = true;
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    st.nextToken();
                    M[j][k] = (long)st.nval;
                    if(M[j][k] < 0)
                        isSymmetric = false;
                }
            }
            for(int j = 0; j < (n + 1) / 2 && isSymmetric; ++j) {
                for(int k = 0; k < n && isSymmetric; ++k)
                    isSymmetric = M[j][k] == M[n - 1 - j][n - 1 - k];
            }
            output.append("Test #" + i + ": " + (isSymmetric ? "Symmetric" : "Non-symmetric") + ".\n");
        }
        System.out.print(output);
	}
}
