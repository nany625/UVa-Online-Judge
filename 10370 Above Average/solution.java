import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int C = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(C-- > 0) {
		    st.nextToken();
		    int N = (int)st.nval, sum = 0;
		    int[] grades = new int[N];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
                grades[i] = (int)st.nval;
                sum += grades[i];
            }
            int count = 0;
            for(Integer i : grades)
                count += (i * N > sum ? 1 : 0);
            output.append(String.format("%.3f%%\n", 100.0 * count / N));
		}
		System.out.print(output);
	}
}
