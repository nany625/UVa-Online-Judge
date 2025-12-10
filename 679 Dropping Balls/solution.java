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
		    int D = (int)st.nval;
		    st.nextToken();
		    int I = (int)st.nval;
		    int ans = 1;
		    while(D-- > 1) {
                if((I & 1) == 1)
                    ans <<= 1;
                else
                    ans = (ans << 1) + 1;
                I = I + (I & 1) >> 1;
            }
            output.append(ans).append('\n');
        }
        System.out.print(output);
	}
}
