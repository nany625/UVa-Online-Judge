import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int I;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (I = (int)st.nval) != 0) {
		    String binaryRep = Integer.toBinaryString(I);
    	    int len = binaryRep.length(), bitsSum = 0;
    	    for(int i = 0; i < len; ++i)
    	        bitsSum += binaryRep.charAt(i) - '0';
    	    output.append("The parity of ").append(binaryRep).append(" is ").append(bitsSum).append(" (mod 2).\n");
		}
		System.out.print(output);
	}
}
