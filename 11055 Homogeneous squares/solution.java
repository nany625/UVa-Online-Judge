import java.io.*;

public class Main {
    static int[][] square = new int[1000][1000];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    st.nextToken();
                    square[i][j] = (int)st.nval;
                }
            }
            boolean homogeneous = true;
            for(int i = 0; i < n - 1 && homogeneous; ++i) {
                for(int j = 0; j < n - 1 && homogeneous; ++j)
                    homogeneous = square[i][j] + square[i + 1][j + 1] == square[i + 1][j] + square[i][j + 1];
            }
            output.append(homogeneous ? "homogeneous\n" : "not homogeneous\n");
        }
		System.out.print(output);
	}
}
