import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
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
                        B += (long)Math.pow(4, A - 1 - j);
                        break;
                    case 'G':
                        B += 2 * (long)Math.pow(4, A - 1 - j);
                        break;
                    case 'T':
                        B += 3 * (long)Math.pow(4, A - 1 - j);
		        }
		    }
		    output.append("Case ").append(i).append(": (").append(A).append(':').append(B).append(")\n");
		}
        System.out.print(output);
	}
}
