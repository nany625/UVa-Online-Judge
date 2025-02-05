// #解法一(正規演算法)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    int N;
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int m = 1;
            while(josephus(N - 1, m) != 11)
                ++m;
    		output.append(m).append('\n');
        }
	    System.out.print(output);
	}
	
	static int josephus(int n, int k) {
        int ans = 0;
        for(int i = 2; i <= n; ++i)
            ans = (ans + k) % i;
        return ans;
    }
}

// #解法二(正規演算法)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    int N;
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            int m = 1;
            while(josephus(N - 1, m) != 11)
                ++m;
    		output.append(m).append('\n');
        }
	    System.out.print(output);
	}
	
	static int josephus(int n, int k) {
        return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
    }
}

// #解法三(捷徑)
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    short[] ans = {
            1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 
            21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 
            42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 
            38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 
            38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 
            72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 
            67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 
            137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 
            49, 5, 22, 54, 52, 113, 15, 66
        };
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
            output.append(ans[N - 13]).append('\n');
	    System.out.print(output);
	}
}
