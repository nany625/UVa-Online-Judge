import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    st.nextToken();
		    int k = (int)st.nval, cigarettes = n;
		     while(n / k > 0) {
                cigarettes += n / k;
                n = n / k + n % k;
            }
            output.append(cigarettes + "\n");
		}
		System.out.print(output);
	}
}
