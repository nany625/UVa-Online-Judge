import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
	        st.nextToken();
	        int n = (int)st.nval, prev = 0, size = 0;
	        while(n-- > 0) {
    	        st.nextToken();
                int curr = (int)st.nval;
                if((size % 2 == 0) == curr > prev)
                    ++size;
                prev = curr;
	        }
            output.append(size).append('\n');
        }
        System.out.print(output);
	}
}
