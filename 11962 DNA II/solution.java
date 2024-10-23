import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
		    String DNA = st.sval;
		    int A = DNA.length();
		    long B = 0;
		    for(int j = 0; j < A; ++j) {
		        switch(DNA.charAt(j)) {
		            case 'C':
                        B += (long)1 << (A - 1 - j << 1);
                        break;
                    case 'G':
                        B += (long)1 << ((A - 1 - j << 1) + 1);
                        break;
                    case 'T':
                        B += 3 * (long)1 << (A - 1 - j << 1);
		        }
		    }
		    output.append("Case ").append(i).append(": (").append(A).append(':').append(B).append(")\n");
		}
        System.out.print(output);
	}
}
