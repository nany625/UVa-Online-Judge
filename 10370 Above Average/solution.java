import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int C = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(C-- > 0) {
		    st.nextToken();
		    int N = (int)st.nval, sum = 0;
		    int[] grades = new int[N];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
                sum += grades[i] = (int)st.nval;
            }
            int count = 0;
            for(Integer i : grades)
                count += (i * N > sum ? 1 : 0);
            output.append(String.format("%.3f%%\n", 100.0 * count / N));
		}
		System.out.print(output);
	}
}
