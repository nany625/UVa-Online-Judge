import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int N = (int)st.nval;
		    int[][] M = new int[N][];
		    int period = 1;
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        M[i] = new int[(int)st.nval];
		        period = period * M[i].length / GCD(period, M[i].length);
		        for(int j = 0; j < M[i].length; ++j) {
		            st.nextToken();
		            M[i][j] = (int)st.nval;
		        }
		    }
		    boolean[] eaten = new boolean[N];
		    int C = 0, D = 0, prev = 0;
		    while(C < N && D - prev < period) {
    			int min = 251, cowNum = 0, count = 0;
    			for(int i = 0; i < N; ++i) {
    				if(eaten[i])
    					continue;
    				if(min > M[i][D % M[i].length]) {
    					min = M[i][D % M[i].length];
    					cowNum = i;
    					count = 1;
    				} else if(min == M[i][D % M[i].length])
    					++count;
    			}
    			if(count == 1) {
    				eaten[cowNum] = true;
    				++C;
    				prev = D + 1;
    			}
    			++D;
    		}
    		output.append(N - C).append(' ').append(prev).append('\n');
		}
		System.out.print(output);
	}
	
	static int GCD(int i, int j) {
	    return j == 0 ? i : GCD(j, i % j);
	}
}
