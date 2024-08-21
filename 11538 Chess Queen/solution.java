import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
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
            long diagonal = 8 * M * (M - 1) * (M - 2) / 6 + 2 * M * (M - 1) * (N - M + 1);
            output.append(vertical + horizontal + diagonal).append('\n');
    	}
        System.out.print(output);
	}
}
