import java.io.*;

public class Main {
    static int KUTI = 10000000, LAKH = 100000, HAJAR = 1000, SHATA = 100;
    static StringBuilder output;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0;
        output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long n = (long)st.nval;
            output.append(String.format("%4d.", ++cases));
            if(n == 0)
                output.append(" 0\n");
            else {
                split(n);
                output.append('\n');
            }
		}
        System.out.print(output);
	}
	
	static void split(long n) {
        if(n >= KUTI) {
            split(n / KUTI);
            output.append(" kuti");
            n %= KUTI;
        }
        if(n >= LAKH) {
            split(n / LAKH);
            output.append(" lakh");
            n %= LAKH;
        }
        if(n >= HAJAR) {
            split(n / HAJAR);
            output.append(" hajar");
            n %= HAJAR;
        }
        if(n >= SHATA) {
            split(n / SHATA);
            output.append(" shata");
            n %= SHATA;
        }
        if(n > 0)
            output.append(' ').append(n);
    }
}
