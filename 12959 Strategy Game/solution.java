import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int J = (int)st.nval;
		    st.nextToken();
		    int R = (int)st.nval, max = 0, winner = 0;
		    int[] points = new int[J];
		    while(R-- > 0) {
		        for(int i = 0; i < J; ++i) {
		            st.nextToken();
		            points[i] += (int)st.nval;
		            if(R == 0) {
		                if(max <= points[i]) {
		                    max = points[i];
		                    winner = i + 1;
		                }
		            }
		        }
		    }
            output.append(winner).append('\n');
		}
		System.out.print(output);
	}
}
