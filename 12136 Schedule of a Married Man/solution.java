import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= N; ++i) {
		    st.nextToken();
		    int h1 = (int)st.nval;
		    st.nextToken();
		    st.nextToken();
		    int m1 = (int)st.nval;
		    st.nextToken();
		    int h2 = (int)st.nval;
		    st.nextToken();
		    st.nextToken();
		    int m2 = (int)st.nval;
		    st.nextToken();
		    int h3 = (int)st.nval;
		    st.nextToken();
		    st.nextToken();
		    int m3 = (int)st.nval;
		    st.nextToken();
		    int h4 = (int)st.nval;
		    st.nextToken();
		    st.nextToken();
		    int m4 = (int)st.nval;
		    h1 = 60 * h1 + m1;
            h2 = 60 * h2 + m2;
            h3 = 60 * h3 + m3;
            h4 = 60 * h4 + m4;
            output.append("Case ").append(i).append(h1 > h4 || h2 < h3 ? ": Hits Meeting\n" : ": Mrs Meeting\n");
        }
		System.out.print(output);
	}
}
