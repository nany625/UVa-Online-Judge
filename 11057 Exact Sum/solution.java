import java.io.*;

public class Main {
    static int MAX_NUM = 1000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int N = (int)st.nval;
		    int[] count = new int[MAX_NUM + 1];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        ++count[(int)st.nval];
		    }
		    st.nextToken();
		    int M = (int)st.nval;
		    int temp = M >> 1;
		    if((M & 1) == 0 && count[temp] >= 2)
		        output.append("Peter should buy books whose prices are ").append(temp).append(" and ").append(temp).append(".\n\n");
		    else {
		        while(count[temp] == 0 || count[M - temp] == 0)
                    --temp;
                output.append("Peter should buy books whose prices are ").append(temp).append(" and ").append(M - temp).append(".\n\n");
		    }
		}
		System.out.print(output);
	}
}
