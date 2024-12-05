import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    short[] primes = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
            31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
            73, 79, 83, 89, 97
        };
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while((st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int) st.nval) != 0)) {
            output.append(String.format("%3d! =", N));
    		short[] count = new short[25];
    		for(int i = 2; i <= N; ++i) {
        	    int j = 0, temp = i;
    		    while(temp > 1) {
    		        if(temp % primes[j] == 0) {
        	            ++count[j];
        	            temp /= primes[j];
    		        } else
    		            ++j;
        	    }
        	}
    		for(int i = 0; i < 25 && count[i] > 0; ++i) {
        		if(i == 15)
        		    output.append("\n      ");
        		output.append(String.format("%3d", count[i]));
    		}
        	output.append('\n');
        }
	    System.out.print(output);
	}
}
