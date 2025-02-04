import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            String s = st.sval;
            long[][] add = {{0, 1}, {1, 0}};
            long a = 1, b = 1;
            for(int i = 0; i < s.length(); ++i) {
                if(s.charAt(i) == 'L') {
                    a = add[0][0] + (add[0][1] = a);
                    b = add[1][0] + (add[1][1] = b);
                } else {
                    a = (add[0][0] = a) + add[0][1];
                    b = (add[1][0] = b) + add[1][1];
                }
            }
            output.append(a).append('/').append(b).append('\n');
        }
		System.out.print(output);
	}
}
