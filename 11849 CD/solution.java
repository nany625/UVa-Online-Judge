import java.io.*;

public class Main {
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
		    int[] Jack = new int[N], Jill = new int[M];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        Jack[i] = (int)st.nval;
		    }
		    for(int i = 0; i < M; ++i) {
		        st.nextToken();
		        Jill[i] = (int)st.nval;
		    }
		    int i = 0, j = 0, count = 0;
		    while(i < N && j < M) {
                if(Jack[i] == Jill[j]) {
                    ++count;
                    ++i;
                    ++j;
                } else if(Jack[i] > Jill[j])
                    ++j;
                else
                    ++i;
            }
            output.append(count).append('\n');
		}
		System.out.print(output);
	}
}
