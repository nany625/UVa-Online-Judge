import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        String s;
        StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_WORD && !(s = st.sval).equals(".")) {
	        int len = s.length();
			boolean found = false;
			for(int i = 1; i <= len / 2 && !found; ++i) {
				if(len % i == 0) {
					int j = i;
					while(j < len && s.substring(0, i).equals(s.substring(j, j + i)))
						j += i;
					if(j >= len) {
						output.append(len / i + "\n");
						found = true;
					}
				}
			}
			if(!found)
			    output.append(1 + "\n");
        }
	    System.out.print(output);
	}
}
