import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long Hashmat = (long)st.nval;
            st.nextToken();
            long opponent = (long)st.nval;
            output.append(Math.abs(Hashmat - opponent)).append('\n');
        }
        System.out.print(output);
	}
}
