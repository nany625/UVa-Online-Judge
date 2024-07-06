import java.io.*;

public class Main {
    static StringBuilder output;
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0;
        output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long n = (long)st.nval;
            output.append(String.format("%4d.", ++cases));
            if(n == 0)
                output.append(" 0\n");
            else {
                split(n);
                output.append("\n");
            }
		}
        System.out.print(output);
	}
	
	static void split(long n) {
        if(n >= Math.pow(10, 7)) {
            split(n / (long)Math.pow(10, 7));
            output.append(" kuti");
            n %= (long)Math.pow(10, 7);
        }
        if(n >= Math.pow(10, 5)) {
            split(n / (long)Math.pow(10, 5));
            output.append(" lakh");
            n %= (long)Math.pow(10, 5);
        }
        if(n >= Math.pow(10, 3)) {
            split(n / (long)Math.pow(10, 3));
            output.append(" hajar");
            n %= (long)Math.pow(10, 3);
        }
        if(n >= Math.pow(10, 2)) {
            split(n / (long)Math.pow(10, 2));
            output.append(" shata");
            n %= (long)Math.pow(10, 2);
        }
        if(n > 0)
            output.append(" " + n);
    }
}
