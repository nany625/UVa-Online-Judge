import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            st.nextToken();
            int c = (int)st.nval;
            output.append(a + b > c && b + c > a && a + c > b ? "OK\n" : "Wrong!!\n");
        }
	    System.out.print(output);
	}
}
