import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int N = (int)st.nval;
		    boolean found = false;
		    for(int i = (int)(N - 9 * Math.log10(N)); i < N && !found; ++i) {
		        int temp = i, sumOfDigits = i;
		        while(temp > 0) {
                    sumOfDigits += temp % 10;
                    temp /= 10;
                }
                if(sumOfDigits == N) {
                    output.append(i).append('\n');
                    found = true;
                }
		    }
		    if(!found)
		        output.append("0\n");
		}
		System.out.print(output);
	}
}
