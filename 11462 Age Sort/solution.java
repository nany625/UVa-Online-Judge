import java.io.*;

public class Main {
    static int[] age = new int[100];
	public static void main(String[] args) throws IOException {
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	int n;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
    	    while(n-- > 0) {
    	        st.nextToken();
    	        ++age[(int)st.nval];
    	    }
    	    boolean firstNum = true;
    	    for(int i = 0; i < 100; ++i) {
    	        if(age[i] > 0) {
    	            do {
    	                if(!firstNum)
    	                    output.append(" ");
    	                output.append(i);
    	                firstNum = false;
    	            } while(--age[i] > 0);
    	        }
    	    }
    	    output.append("\n");
    	}
	    System.out.print(output);
	}
}
