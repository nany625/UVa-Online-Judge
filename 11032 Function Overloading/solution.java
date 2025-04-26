import java.io.*;

public class Main {
    static int MAX_NUM = 10000000;
    static int[] fun = new int[MAX_NUM + 1], count = new int[MAX_NUM + 1];
    public static void main(String[] args) throws IOException {
        for(int n = 1; n <= MAX_NUM; ++n) {
            int temp = n + sod(n);
            if(temp <= MAX_NUM && fun[temp] == 0)
                fun[temp] = n;
            count[n] = count[n - 1] + (fun[n] == 0 ? 1 : 0);
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= cases; ++i) {
            String[] tokens = br.readLine().split("\\s+");
            if(tokens.length == 1) {
                int a = Integer.parseInt(tokens[0]);
                output.append("Case ").append(i).append(": ").append(fun[a] == 0 ? -1 : fun[a]).append('\n');
            } else
                output.append("Case ").append(i).append(": ").append(count[Integer.parseInt(tokens[1])] - count[Integer.parseInt(tokens[0]) - 1]).append('\n');
        }
        System.out.print(output);
    }
    
    static int sod(int n) {
        int ans = 0;
        while(n > 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
}
