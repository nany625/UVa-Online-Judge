import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        long M, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (M = (long)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (long)st.nval) != 0) {
            if(M > N) {
                long temp = M;
                M = N;
                N = temp;
            }
            long vertical = M * (M - 1) * N;
            long horizontal = N * (N - 1) * M;
            long diagonal = (M * (M - 1) * (M - 2) << 3) / 6 + (M * (M - 1) * (N - M + 1) << 1);
            output.append(vertical + horizontal + diagonal).append('\n');
    	}
        System.out.print(output);
	}
}
