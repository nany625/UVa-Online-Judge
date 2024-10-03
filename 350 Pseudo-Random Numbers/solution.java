import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int Z = (int)st.nval;
		    st.nextToken();
		    int I = (int)st.nval;
		    st.nextToken();
		    int M = (int)st.nval;
		    st.nextToken();
		    int L = (int)st.nval;
		    if(Z == 0 && I == 0 && M == 0 && L == 0)
		        break;
		    short[] order = new short[10000];
		    short count = 1;
		    do {
		        order[L] = count++;
		        L = (Z * L + I) % M;
		    } while(order[L] == 0);
		    output.append("Case ").append(++cases).append(": ").append(count - order[L]).append('\n');
		}
		System.out.print(output);
	}
}
