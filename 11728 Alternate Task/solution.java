// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        int[] table = new int[1000];
        table[0] = 1;
        for(int i = 2; i <= 1000; ++i) {
            int temp = factorSum(i);
            if(temp <= 1000)
                table[temp - 1] = i;
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, S;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) != 0)
	        output.append("Case ").append(++cases).append(": ").append(table[S - 1] != 0 ? table[S - 1] : -1).append('\n');
        System.out.print(output);
	}
	
	static int factorSum(int n) {
        int result = 1 + n, limit = (int)Math.sqrt(n);
        for(int i = 2; i <= limit; ++i) {
            if(n % i == 0)
                result += i + n / i;
        }
        if(Math.sqrt(n) == limit)
            result -= limit;
        return result;
    }
}

// #解法二
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, S;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) != 0) {
            if(S == 1) {
                output.append("Case ").append(++cases).append(": 1\n");
                continue;
            }
            int ans = S - 1, limit = (int)Math.ceil(Math.sqrt(1 + (S << 3)) - 1) >> 1;
            while(ans >= limit && factorSum(ans) != S)
	            --ans;
	        output.append("Case ").append(++cases).append(": ").append(ans >= limit ? ans : -1).append('\n');
        }
        System.out.print(output);
	}
	
	static int factorSum(int n) {
        int result = 1 + n, limit = (int)Math.sqrt(n);
        for(int i = 2; i <= limit; ++i) {
            if(n % i == 0)
                result += i + n / i;
        }
        if(Math.sqrt(n) == limit)
            result -= limit;
        return result;
    }
}
