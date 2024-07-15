import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
    		int M = (int)st.nval;
    		st.nextToken();
    		int N = (int)st.nval;
    		st.nextToken();
    		int Q = (int)st.nval;
    		output.append(M + " " + N + " " + Q + "\n");
            String[] rec = new String[M];
            for(int i = 0; i < M; ++i)
		        rec[i] = br.readLine();
            while(Q-- > 0) {
                st.nextToken();
        		int r = (int)st.nval;
        		st.nextToken();
        		int c = (int)st.nval;
        		boolean isSquare = true;
        		int range = 0;
        		do {
        		    ++range;
        		    if(r - range < 0 || r + range >= M || c - range < 0 || c + range >= N)
                        isSquare = false;
                    else {
                        for(int col = c - range; col < c + range && isSquare; ++col) {
                            if(rec[r - range].charAt(col) != rec[r].charAt(c))
                                isSquare = false;
                        }
                        for(int row = r - range; row < r + range && isSquare; ++row) {
                            if(rec[row].charAt(c + range) != rec[r].charAt(c))
                                isSquare = false;
                        }
                        for(int col = c + range; col >= c - range + 1 && isSquare; --col) {
                            if(rec[r + range].charAt(col) != rec[r].charAt(c))
                                isSquare = false;
                        }
                        for(int row = r + range; row >= r - range + 1 && isSquare; --row) {
                            if(rec[row].charAt(c - range) != rec[r].charAt(c))
                                isSquare = false;
                        }
                    }
        		} while(isSquare);
        		output.append(2 * range - 1 + "\n");
            }
		}
		System.out.print(output);
	}
}
