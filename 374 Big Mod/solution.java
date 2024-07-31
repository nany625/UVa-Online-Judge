import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    long B = (long)st.nval;
    	    st.nextToken();
    	    int P = (int)st.nval;
    	    st.nextToken();
    	    int M = (int)st.nval;
    	    output.append(bigMod(B, P, M) + "\n");
    	}
        System.out.print(output);
	}
	
	static int bigMod(long B, int P, int M) {
        if(P == 0)
            return 1 % M;
        if(P == 1)
            return (int)(B % M);
        int temp = bigMod(B, P / 2, M);
        if(P % 2 == 0)
            return temp * temp % M;
        return (int)(temp * temp * B % M);
    }
}
