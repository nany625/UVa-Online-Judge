import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
		    int k = (int)st.nval;
		    st.nextToken();
		    int w = (int)st.nval;
		    st.nextToken();
		    String sign = st.sval;
		    --w;
		    while(w-- > 0) {
		        st.nextToken();
		        String message = st.sval;
		        int temp = k, len = sign.length();
		        while(temp > 0 && !sign.endsWith(message.substring(0, temp)))
                    --temp;
                sign += message.substring(temp, k);
		    }
		    output.append(sign.length()).append('\n');
		}
		System.out.print(output);
	}
}
