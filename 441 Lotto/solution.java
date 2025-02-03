import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int k;
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (k = (int)st.nval) != 0) {
		    if(!firstCase)
		        output.append('\n');
		    int[] S = new int[k];
		    for(int i = 0; i < k; ++i) {
		        st.nextToken();
		        S[i] = (int)st.nval;
		    }
		    for(int i = 0; i < k - 5; ++i) {
                for(int j = i + 1; j < k - 4; ++j) {
                    for(int l = j + 1; l < k - 3; ++l) {
                        for(int m = l + 1; m < k - 2; ++m) {
                            for(int n = m + 1; n < k - 1; ++n) {
                                for(int o = n + 1; o < k; ++o)
                                    output.append(S[i]).append(' ').append(S[j]).append(' ').append(S[l]).append(' ').append(S[m]).append(' ').append(S[n]).append(' ').append(S[o]).append('\n');
                            }
                        }
                    }
                }
            }
            firstCase = false;
		}
		System.out.print(output);
	}
}
