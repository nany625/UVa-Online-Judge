import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int N = (int)st.nval;
		    st.nextToken();
		    int R = (int)st.nval;
		    if(N == R) {
                output.append("*\n");
                while(R-- > 0)
                    st.nextToken();
                continue;
            }
            if(R << 1 >= N) {
                int[] returned = new int[R];
                for(int i = 0; i < R; ++i) {
                    st.nextToken();
                    returned[i] = (int)st.nval;
                }
                Arrays.sort(returned);
                for(int i = 1; i < returned[0]; ++i)
                    output.append(i).append(' ');
                for(int i = 0; i < R - 1; ++i) {
                    for(int j = returned[i] + 1; j < returned[i + 1]; ++j)
                        output.append(j).append(' ');
                }
                for(int i = returned[R - 1] + 1; i <= N; ++i)
                    output.append(i).append(' ');
            } else {
                boolean[] returned = new boolean[N];
                while(R-- > 0) {
                    st.nextToken();
                    returned[(int)st.nval - 1] = true;
                }
                for(int i = 0; i < N; ++i) {
                    if(!returned[i])
                        output.append(i + 1).append(' ');
                }
    	    }
		    output.append('\n');
		}
		System.out.print(output);
	}
}
