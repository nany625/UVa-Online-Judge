// #解法一
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= cases; ++i) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int k = (int)st.nval;
            output.append("Case ").append(i).append(": ").append(josephus(n, k) + 1).append("\n");
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

// #解法二
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= cases; ++i) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int k = (int)st.nval;
            output.append("Case ").append(i).append(": ").append(josephus(n, k) + 1).append("\n");
        }
        System.out.print(output);
    }
    
    static int josephus(int n, int k) {
        return n == 1 ? 0 : (josephus(n - 1, k) + k) % n;
    }
}
