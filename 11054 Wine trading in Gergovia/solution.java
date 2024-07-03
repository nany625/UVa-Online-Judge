import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    long work = 0;
		    int curr = 0;
		    while(n-- > 0) {
		        st.nextToken();
		        curr += (short)st.nval;
		        work += Math.abs(curr);
		    }
		    output.append(work + "\n");
		}
        System.out.print(output);
    }	
}
