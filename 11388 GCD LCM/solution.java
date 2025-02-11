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
		    int G = (int)st.nval;
		    st.nextToken();
		    int L = (int)st.nval;
		    if(L % G == 0)
		        output.append(G).append(' ').append(L).append('\n');
		    else
		        output.append("-1\n");
		}
		System.out.print(output);
	}
}
