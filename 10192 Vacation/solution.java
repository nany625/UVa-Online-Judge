import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = 0;
        String father;
        StringBuilder output = new StringBuilder();
        while((father = br.readLine()) != null && father.charAt(0) != '#') {
            String mother = br.readLine();
            int m = father.length(), n = mother.length();
            int[] L = new int[n + 1];
            for(int i = 0; i < m; ++i) {
                int prev = 0;
                for(int j = 1; j <= n; ++j) {
                    int temp = L[j];
                    if(father.charAt(i) == mother.charAt(j - 1))
                        L[j] = prev + 1;
                    else
                        L[j] = Math.max(L[j], L[j - 1]);
                    prev = temp;
                }
            }
            output.append("Case #").append(++cases).append(": you can visit at most ").append(L[n]).append(" cities.\n");
        }
	    System.out.print(output);
	}
}
