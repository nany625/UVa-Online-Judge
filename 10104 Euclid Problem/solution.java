import java.io.*;

public class Main {
    static int[] X = new int[1], Y = new int[1];
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int A = (int)st.nval;
            st.nextToken();
            int B = (int)st.nval, D = GCD(A, B);
            output.append(X[0]).append(' ').append(Y[0]).append(' ').append(D).append('\n');
        }
        System.out.print(output);
	}
	
	static int GCD(int A, int B) {
		if(A % B == 0) {
			X[0] = 0;
			Y[0] = 1;
			return B;
		}
		if(B % A == 0) {
			X[0] = 1;
			Y[0] = 0;
			return A;
		}
		if(A >= B) {
			int value = GCD(A + B * (-A / B), B);
			Y[0] -= X[0] * (A / B);
			return value;
		}
		int value = GCD(A, B + A * (-B / A));
		X[0] -= Y[0] * (B / A);
		return value;
	}
}
