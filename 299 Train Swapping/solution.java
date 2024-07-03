import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int L = (int)st.nval, swap = 0;
            int[] a = new int[L];
	        for(int i = 0; i < L; ++i) {
                st.nextToken();
	            a[i] = (int)st.nval;
                for(int j = 0; j < i; ++j) {
                    if(a[j] > a[i])
                        ++swap;
                }
	        }
	        output.append("Optimal train swapping takes " + swap + " swaps.\n");
		}
        System.out.print(output);
	}
}
