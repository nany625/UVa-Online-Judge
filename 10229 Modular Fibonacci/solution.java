import java.io.*;

public class Main {
    static long[][] temp = new long[2][2];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            st.nextToken();
            int m = (int)st.nval;
            if(n <= 1) {
                output.append(n).append('\n');
                continue;
            }
            output.append(powerMatrix(new long[][]{{1, 1}, {1, 0}}, n - 1, (1 << m) - 1)).append('\n');
        }
        System.out.print(output);
	}
	
	static void multiplyMatrix(long[][] a, long[][] b, int mod) {
	    temp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) & mod;
	    temp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) & mod;
	    temp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) & mod;
	    temp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) & mod;
	    System.arraycopy(temp[0], 0, a[0], 0, 2);
	    System.arraycopy(temp[1], 0, a[1], 0, 2);
	}
	
	static int powerMatrix(long[][] matrix, int n, int mod) {
	    long[][] result = {{1, 0}, {0, 1}};
	    while(n > 0) {
	        if((n & 1) == 1)
	            multiplyMatrix(result, matrix, mod);
	        multiplyMatrix(matrix, matrix, mod);
	        n >>= 1;
	    }
	    return (int)result[0][0];
	}
}
