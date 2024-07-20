import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(t-- > 0) {
		    st.nextToken();
		    int magenta = (int)st.nval;
		    st.nextToken();
		    int yellow = (int)st.nval;
		    st.nextToken();
		    int cyan = (int)st.nval;
		    st.nextToken();
		    String pixels = st.sval;
		    int len = pixels.length();
		    for(int i = 0; i < len && magenta >= 0 && yellow >= 0 && cyan >= 0; ++i) {
                switch(pixels.charAt(i)) {
                    case 'M':
                        --magenta;
                        break;
                    case 'Y':
                        --yellow;
                        break;
                    case 'C':
                        --cyan;
                        break;
                    case 'R':
                        --magenta;
                        --yellow;
                        break;
                    case 'B':
                        --magenta;
                        --yellow;
                        --cyan;
                        break;
                    case 'G':
                        --yellow;
                        --cyan;
                        break;
                    case 'V':
                        --magenta;
                        --cyan;
                }
            }
            if(magenta >= 0 && yellow >= 0 && cyan >= 0)
                output.append("YES " + magenta + " " + yellow + " " + cyan + "\n");
            else
                output.append("NO\n");
		}
		System.out.print(output);
	}
}
