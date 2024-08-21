import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= n; ++i) {
		    Coordinate src = new Coordinate(), dest = new Coordinate();
		    st.nextToken();
		    src.x = (long)st.nval;
		    st.nextToken();
		    src.y = (long)st.nval;
		    st.nextToken();
		    dest.x = (long)st.nval;
		    st.nextToken();
		    dest.y = (long)st.nval;
		    output.append("Case ").append(i).append(": ").append((src.x + src.y + dest.x + dest.y + 1) * (dest.x + dest.y - src.x - src.y) / 2 + dest.x - src.x).append('\n');
		}
		System.out.print(output);
	}
}

class Coordinate {
    long x, y;
}
