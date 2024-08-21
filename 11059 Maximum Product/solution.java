import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int M = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            int[] S = new int[N];
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                S[i] = (int)st.nval;
            }
            long P = 0, curr;
            for(int i = 0; i < N; ++i) {
                curr = S[i];
                P = Math.max(P, curr);
                for(int j = i + 1; j < N; ++j) {
                    curr *= S[j];
                    P = Math.max(P, curr);
                }
            }
            output.append("Case #").append(++M).append(": The maximum product is ").append(P).append(".\n\n");
        }
        System.out.print(output);
	}
}
