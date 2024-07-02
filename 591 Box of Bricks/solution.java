import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            int set = 0, n;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
    		    short[] h = new short[n];
    		    short total = 0;
    		    for(int i = 0; i < n; ++i) {
    		        st.nextToken();
    		        h[i] = (short)st.nval;
    		        total += h[i];
    		    }
    		    total /= n;
    		    short moves = 0;
    		    for(Short s : h) {
    		        if(s > total)
    		            moves += s - total;
    		    }
    		    System.out.println("Set #" + (++set) + "\nThe minimum number of moves is " + moves + ".\n");
    		}
        } catch(IOException e) {};
	}
}
