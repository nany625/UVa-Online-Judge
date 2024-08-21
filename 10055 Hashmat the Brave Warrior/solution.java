import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long Hashmat = (long)st.nval;
            st.nextToken();
            long opponent = (long)st.nval;
            output.append(Math.abs(Hashmat - opponent)).append('\n');
        }
        bw.write(output.toString());
        bw.flush();
        bw.close();
	}
}
