import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int A, B;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (A = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (B = (int)st.nval) != 0) {
		    ArrayList<Integer> X = new ArrayList<>();
		    int sizeX = 0;
		    while(A-- > 0) {
		        st.nextToken();
		        int temp = (int)st.nval;
		        if(X.isEmpty() || (temp > X.get(sizeX - 1))) {
                    X.add(temp);
                    ++sizeX;
                }
		    }
		    ArrayList<Integer> Y = new ArrayList<>();
		    int sizeY = 0;
		    while(B-- > 0) {
		        st.nextToken();
		        int temp = (int)st.nval;
		        if(Y.isEmpty() || (temp > Y.get(sizeY - 1))) {
                    Y.add(temp);
                    ++sizeY;
                }
		    }
		    int i = 0, j = 0, countX = 0, countY = 0;
            while(i < sizeX && j < sizeY) {
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
            countX += sizeX - i;
            countY += sizeY - j;
            output.append(Math.min(countX, countY) + "\n");
		}
		System.out.print(output);
	}
}
