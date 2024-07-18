import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int K;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (K = (int)st.nval) != 0) {
            st.nextToken();
            int N = (int)st.nval;
            st.nextToken();
            int M = (int)st.nval;
            while(K-- > 0) {
                st.nextToken();
                int X = (int)st.nval;
                st.nextToken();
                int Y = (int)st.nval;
                if(X == N || Y == M)
    				output.append("divisa\n");
    			else if(X > N && Y > M)
    				output.append("NE\n");
    			else if(X < N && Y > M)
    				output.append("NO\n");
    			else if(X < N && Y < M)
    				output.append("SO\n");
    			else
    				output.append("SE\n");
            }
        }
        System.out.print(output);
	}
}
