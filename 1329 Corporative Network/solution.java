import java.io.*;

public class Main {
    static int MAX_NUM = 20000;
    static int[] root = new int[MAX_NUM + 1], length = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
    		int N = (int)st.nval;
    		for(int n = 1; n <= N; ++n)
                length[root[n] = n] = 0;
    		char command;
    		while((command = (char)br.read()) != 'O') {
    		    if(command == 'E') {
    		        st.nextToken();
                    int I = (int)st.nval;
                    findRoot(I);
                    output.append(length[I]).append('\n');
                } else {
                    st.nextToken();
                    int I = (int)st.nval;
                    st.nextToken();
                    int J = (int)st.nval;
                    root[I] = J;
                    length[I] = Math.abs(I - J) % 1000;
                }
    		}
		}
		System.out.print(output);
	}
    
    static int findRoot(int child) {
        if(root[child] != child) {
            int temp = findRoot(root[child]);
            length[child] += length[root[child]];
            return root[child] = temp;
        }
        return child;
    }
}
