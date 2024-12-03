import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            st.nextToken();
            st.nextToken();
            long[] M = new long[(int)st.nval * (int)st.nval];
            boolean isSymmetric = true;
            for(int j = 0; j < M.length; ++j) {
                st.nextToken();
                M[j] = (long)st.nval;
                if(M[j] < 0)
                    isSymmetric = false;
            }
            for(int j = 0; j < M.length >> 1 && isSymmetric; ++j)
                isSymmetric = M[j] == M[M.length - 1 - j];
            output.append("Test #").append(i).append(isSymmetric ? ": Symmetric.\n" : ": Non-symmetric.\n");
        }
        System.out.print(output);
	}
}
