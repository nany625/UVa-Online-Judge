import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            short[] b = new short[N];
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                b[i] = (short)st.nval;
            }
            boolean isB2 = true;
            for(int i = 0; i < N - 1 && isB2; ++i) {
                if(b[i] < 1 || b[i] >= b[i + 1])
                    isB2 = false;
            }
            if(!isB2)
                output.append("Case #").append(++cases).append(": It is not a B2-Sequence.\n\n");
            else {
                boolean[] diff = new boolean[b[N - 1] - b[0]];
                for(int i = 0; i < N - 1 && isB2; ++i) {
                    for(int j = i + 1; j < N && isB2; ++j) {
                        if(!diff[b[j] - b[i] - 1])
                            diff[b[j] - b[i] - 1] = true;
                        else
                            isB2 = false;
                    }
                }
                output.append("Case #").append(++cases).append(isB2 ? ": It is a B2-Sequence.\n\n" : ": It is not a B2-Sequence.\n\n");
            }
        }
        System.out.print(output);
	}
}
