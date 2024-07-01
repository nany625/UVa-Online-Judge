import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                int n = (int)st.nval, x = 0, remainder = 0;
                do {
                    remainder = (10 * remainder + 1) % n;
                    ++x;
                } while(remainder != 0);
                System.out.println(x);
            }
	    } catch(IOException e) {}
	}
}
