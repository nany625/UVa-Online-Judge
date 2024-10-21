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
            int M = (int)st.nval;
            char[] ans = new char[M + 1];
            for(int i = 1; i <= M; ++i) {
                st.nextToken();
			    ans[i] = (char)(st.nval + '0');
			    st.nextToken();
			    ans[i] += (int)st.nval;
            }
            ans[0] = '0';
    	    for(int i = M; i >= 1; --i) {
    	        ans[i - 1] += (ans[i] - '0') / 10;
    	        ans[i] = (char)((ans[i] - '0') % 10 + '0');
    	    }
    	    if(ans[0] == '1')
    	        output.append('1');
    	    for(int i = 1; i <= M; ++i)
    	        output.append(ans[i]);
    	    output.append('\n');
    	    if(N > 0)
			    output.append('\n');
        }
        System.out.print(output);
	}
}
