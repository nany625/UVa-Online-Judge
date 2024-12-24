import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int N = (int)st.nval;
		int[] temp = new int[2];
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= N; ++i) {
		    st.nextToken();
		    int K = (int)st.nval;
		    for(int j = 2, count = 0; count < 2; ++j) {
                if(K % j == 0)
                    temp[count++] = j;
            }
		    output.append("Case #").append(i).append(": ").append(K).append(" = ").append(temp[0]).append(" * ").append(K / temp[0]).append(" = ").append(temp[1]).append(" * ").append(K / temp[1]).append('\n');
		}
		System.out.print(output);
	}
}
