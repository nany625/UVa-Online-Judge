import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try {
            StreamTokenizer st = new StreamTokenizer(System.in);
            while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
                int number = (int)st.nval;
                int i = (int)Math.ceil((-1 + Math.sqrt(1 + 8 * number)) / 2);
                int a = i + 1 - number + (i - 1) * i / 2;
                int b = number - (i - 1) * i / 2;
                if(i % 2 == 1)
                    System.out.println("TERM " + number + " IS " + a + "/" + b);
    			else
    			    System.out.println("TERM " + number + " IS " + b + "/" + a);
    		}
        } catch(IOException e) {};
	}
}
