import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int A, B;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (A = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (B = (int)st.nval) != 0) {
		    ArrayList<Integer> X = new ArrayList<>();
		    while(A-- > 0) {
		        st.nextToken();
		        int temp = (int)st.nval;
		        if(X.isEmpty() || (temp > X.get(X.size() - 1)))
                    X.add(temp);
		    }
		    ArrayList<Integer> Y = new ArrayList<>();
		    while(B-- > 0) {
		        st.nextToken();
		        int temp = (int)st.nval;
		        if(Y.isEmpty() || (temp > Y.get(Y.size() - 1)))
                    Y.add(temp);
		    }
		    int i = 0, j = 0, countX = 0, countY = 0;
            while(i < X.size() && j < Y.size()) {
                if(X.get(i).equals(Y.get(j))) {
                    ++i;
                    ++j;
                } else if(X.get(i) < Y.get(j)) {
                    ++countX;
                    ++i;
                } else {
                    ++countY;
                    ++j;
                }
            }
            countX += X.size() - i;
            countY += Y.size() - j;
            output.append(Math.min(countX, countY)).append('\n');
		}
		System.out.print(output);
	}
}
