import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    char top = '1', north = '2', west = '3', east = '4', south = '5', bottom = '6';
		    while(n-- > 0) {
		        st.nextToken();
		        char temp = top;
		        switch(st.sval.charAt(0)) {
                    case 'n':
                        top = south;
                        south = bottom;
                        bottom = north;
                        north = temp;
                        break;
                    case 'e':
                        top = west;
                        west = bottom;
                        bottom = east;
                        east = temp;
                        break;
                    case 's':
                        top = north;
                        north = bottom;
                        bottom = south;
                        south = temp;
                        break;
                    case 'w':
                        top = east;
                        east = bottom;
                        bottom = west;
                        west = temp;
		        }
            }
		    output.append(top).append('\n');
		}
		System.out.print(output);
	}
}
