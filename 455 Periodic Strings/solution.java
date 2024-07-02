import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int N = (int)st.nval;
            boolean blankLine = false;
            while(N-- > 0) {
    	        if(blankLine)
    				System.out.println();
    	        st.nextToken();
    	        String s = st.sval;
    	        int len = s.length();
    			boolean found = false;
    			for(int k = 1; k <= len / 2 && !found; ++k) {
    				if(len % k == 0) {
    					int i = k;
    					while(i < len && s.substring(0, k).equals(s.substring(i, i + k)))
    						i += k;
    					if(i >= len) {
    						System.out.println(k);
    						found = true;
    					}
    				}
    			}
    			if(!found)
    			    System.out.println(len);
    			blankLine = true;
            }
        } catch(IOException e) {};
	}
}
