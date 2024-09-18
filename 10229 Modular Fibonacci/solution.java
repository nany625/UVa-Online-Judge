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
            if(n == 0) {
                output.append("0\n");
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
	    for(int i = 0; i < 2; ++i)
	        System.arraycopy(temp[i], 0, a[i], 0, 2);
	}
	
	static long powerMatrix(long[][] matrix, int n, int mod) {
	    long[][] result = {{1, 0}, {0, 1}};
	    while(n > 0) {
	        if((n & 1) == 1)
	            multiplyMatrix(result, matrix, mod);
	        multiplyMatrix(matrix, matrix, mod);
	        n >>= 1;
	    }
	    return result[0][0];
	}
}
