import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int[] table = new int[499];
        table[0] = 1;
		for(int i = 3; i < 501; ++i) {
            table[i - 2] = table[i - 3];
            for(int j = 1; j < i; ++j)
                table[i - 2] += GCD(i, j);
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
		    output.append(table[N - 2]).append('\n');
        System.out.print(output);
    }
    
    static int GCD(int i, int j) {
	    return j == 0 ? i : GCD(j, i % j);
	}
}
