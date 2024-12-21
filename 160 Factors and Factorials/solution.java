import java.io.*;

public class Main {
    static short[] primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
        73, 79, 83, 89, 97
    };
    static short[][] table = new short[101][25];
    static int[] size = new int[101];
	public static void main(String[] args) throws IOException {
	    for(int n = 2; n <= 100; ++n)
	    	initTable(n);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while((st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int) st.nval) != 0)) {
            output.append(String.format("%3d! =", N));
    		for(int i = 0; i < size[N]; ++i) {
        		if(i == 15)
        		    output.append("\n      ");
        		output.append(String.format("%3d", table[N][i]));
    		}
        	output.append('\n');
        }
	    System.out.print(output);
	}
	
	static void initTable(int n) {
        int temp = n;
        for(int i = 0; i < size[n - 1]; ++i)
            table[n][i] = table[n - 1][i];
        size[n] = size[n - 1];
        for(int i = 0; i < size[temp - 1] && n > 1; ++i) {
            while(n % primes[i] == 0) {
                ++table[temp][i];
                n /= primes[i];
            }
        }
        if(n > 1)
            table[temp][size[temp]++] = 1;
    }
}
