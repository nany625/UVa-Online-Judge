import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
            int[] sequence = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                sequence[i] = (int)st.nval;
            }
            int limit = 36;
            while(limit-- > 0) {
                boolean ZERO = true;
                for(int i = 0; i < n && ZERO; ++i)
                    ZERO = sequence[i] == 0;
                if(ZERO)
                    break;
                int temp = sequence[0];
                for(int i = 0; i < n - 1; ++i)
                    sequence[i] = Math.abs(sequence[i + 1] - sequence[i]);
                sequence[n - 1] = Math.abs(temp - sequence[n - 1]);
            }
            output.append(limit > 0 ? "ZERO\n" : "LOOP\n");
		}
		System.out.print(output);
	}
}
