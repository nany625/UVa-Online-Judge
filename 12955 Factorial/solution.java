import java.io.*;

public class Main {
    static int factorial[] = {40320, 5040, 720, 120, 24, 6, 2, 1};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int N = (int)st.nval, k = 0;
		    for(int i = 0; N > 0; ++i) {
                k += N / factorial[i];
                N %= factorial[i];
            }
            output.append(k).append('\n');
		}
		System.out.print(output);
	}
}
