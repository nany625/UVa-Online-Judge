import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    Coordinate gopher = new Coordinate(), dog = new Coordinate();
		    st.nextToken();
		    gopher.x = st.nval;
		    st.nextToken();
		    gopher.y = st.nval;
		    st.nextToken();
		    dog.x = st.nval;
		    st.nextToken();
		    dog.y = st.nval;
		    Coordinate[] holes = new Coordinate[n];
		    boolean escape = false;
		    for(int i = 0; i < n; ++i) {
		        holes[i] = new Coordinate();
		        st.nextToken();
		        holes[i].x = st.nval;
		        st.nextToken();
		        holes[i].y = st.nval;
		        if(!escape && 2 * dist(gopher, holes[i]) <= dist(dog, holes[i])) {
		            output.append(String.format("The gopher can escape through the hole at (%.3f,%.3f).\n", holes[i].x, holes[i].y));
		            escape = true;
		        }
		    }
		    if(!escape)
		        output.append("The gopher cannot escape.\n");
		}
		System.out.print(output);
	}
	
	static double dist(Coordinate i, Coordinate j) {
	    return Math.hypot(i.x - j.x, i.y - j.y);
	}
}

class Coordinate {
    double x, y;
}
