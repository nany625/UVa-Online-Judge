import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
		    int f = (int)st.nval;
            long sum = 0;
            while(f-- > 0) {
                st.nextToken();
                long size = (long)st.nval;
                st.nextToken();
                st.nextToken();
                sum += size * st.nval;
            }
            output.append(sum + "\n");
		}
		System.out.print(output);
	}
}
