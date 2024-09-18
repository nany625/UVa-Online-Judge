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
            int n = (int)st.nval, p = 0;
            int[] instructions = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                switch(st.sval.charAt(0)) {
                    case 'L':
                        p += (instructions[i] = -1);
                        break;
                    case 'R':
                        p += (instructions[i] = 1);
                        break;
                    case 'S':
                        st.nextToken();
                        st.nextToken();
                        p += (instructions[i] = instructions[(int)st.nval - 1]);
                }
            }
            output.append(p).append('\n');
        }
        System.out.print(output);
	}
}
