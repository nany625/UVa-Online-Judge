import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    char top = '1', north = '2', west = '3', east = '4', south = '5', bottom = '6';
		    while(n-- > 0) {
		        st.nextToken();
		        char temp = top;
		        if(st.sval.equals("north")) {
                    top = south;
                    south = bottom;
                    bottom = north;
                    north = temp;
                } else if(st.sval.equals("east")) {
                    top = west;
                    west = bottom;
                    bottom = east;
                    east = temp;
                } else if(st.sval.equals("south")) {
                    top = north;
                    north = bottom;
                    bottom = south;
                    south = temp;
                } else if(st.sval.equals("west")) {
                    top = east;
                    east = bottom;
                    bottom = west;
                    west = temp;
                }
		    }
		    output.append(top + "\n");
		}
		System.out.print(output);
	}
}
