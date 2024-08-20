import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int[] secretKeys = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                secretKeys[i] = (int)st.nval - 1;
            }
            int k;
            char[] cipher = new char[n];
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (k = (int)st.nval) != 0) {
                StringBuilder message = new StringBuilder(br.readLine());
                while(message.length() != n)
                    message.append(" ");
                for(int i = 0; i < n; ++i) {
                    int[] nextIndex = new int[n];
                    boolean[] visited = new boolean[n];
                    visited[nextIndex[0] = i] = true;
                    int cycle = 1;
                    while(!visited[secretKeys[nextIndex[cycle - 1]]]) {
                        nextIndex[cycle] = secretKeys[nextIndex[cycle - 1]];
                        visited[nextIndex[cycle++]] = true;
                    }
                    cipher[nextIndex[k % cycle]] = message.charAt(i);
                }
                for(char ch : cipher)
                    output.append(ch);
                output.append("\n");
            }
            output.append("\n");
        }
        System.out.print(output);
    }
}
