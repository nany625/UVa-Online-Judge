import java.io.*;

public class Main {
    static int[] X = new int[1], Y = new int[1];
	public static void main(String[] args) {
	    try {
    	    StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                int A = (int)st.nval;
                st.nextToken();
                int B = (int)st.nval, D = GCD(A, B);
                System.out.println(X[0] + " " + Y[0] + " " + D);
            }
	    } catch(IOException e) {}
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
			Y[0] = Y[0] - X[0] * (A / B);
			return value;
		} else {
			int value = GCD(A, B + A * (-B / A));
			X[0] = X[0] - Y[0] * (B / A);
			return value;
		}
	}
}
