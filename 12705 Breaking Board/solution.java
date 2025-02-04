import java.io.*;
import java.util.*;

public class Main {
    static int[] costs = {
        2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 
        6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 
        7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 
        10, 10, 10, 11, 11, 12
    };
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            String L = br.readLine();
            int[] count = new int[36];
            for(int i = 0; i < L.length(); ++i) {
                if(Character.isDigit(L.charAt(i)))
                    ++count[L.charAt(i) - '0'];
                else if(Character.isUpperCase(L.charAt(i)))
                    ++count[L.charAt(i) - 'A' + 10];
            }
            Arrays.sort(count);
            int minCost = 0;
            for(int i = 35; i >= 0 && count[i] > 0; --i)
                minCost += count[i] * costs[35 - i];
            output.append(minCost).append('\n');
        }
		System.out.print(output);
	}
}
