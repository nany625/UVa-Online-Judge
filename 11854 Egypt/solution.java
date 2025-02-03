import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int[] lengths = new int[3];
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (lengths[0] = (int)st.nval) != 0) {
		    st.nextToken();
		    lengths[1] = (int)st.nval;
		    st.nextToken();
		    lengths[2] = (int)st.nval;
		    Arrays.sort(lengths);
		    output.append(lengths[0] * lengths[0] + lengths[1] * lengths[1] == lengths[2] * lengths[2] ? "right\n" : "wrong\n");
		}
		System.out.print(output);
	}
}
