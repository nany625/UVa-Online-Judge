import java.io.*;
import java.util.*;

public class Main {
    static int[][] table = {
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {1, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {3, 1, 0, 0}, 
        {3, 1, 1, 0}, 
        {4, 2, 1, 0}, 
        {4, 2, 1, 1}, 
        {7, 2, 1, 1}, 
        {7, 4, 1, 1}
    };
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int N = (int)st.nval;
		    st.nextToken();
		    int M = (int)st.nval;
		    if(N == 0 || M == 0)
		        break;
		    int[] generator1 = new int[4], generator2 = new int[4];
		    while(N-- > 0) {
		        st.nextToken();
                int digit = (int)st.nval;
                for(int i = 0; i < 4; ++i)
                    generator1[i] += table[digit][i];
            }
            while(M-- > 0) {
		        st.nextToken();
                int digit = (int)st.nval;
                for(int i = 0; i < 4; ++i)
                    generator2[i] += table[digit][i];
            }
            output.append(Arrays.equals(generator1, generator2) ? "YES\n" : "NO\n");
		}
		System.out.print(output);
	}
}
