import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = 0;
        String father;
        StringBuilder output = new StringBuilder();
        while((father = br.readLine()) != null && father.charAt(0) != '#') {
            String mother = br.readLine();
            int[] L = new int[mother.length() + 1];
            for(int i = 0; i < father.length(); ++i) {
                int prev = 0;
                for(int j = 1; j <= mother.length(); ++j) {
                    int temp = L[j];
                    if(father.charAt(i) == mother.charAt(j - 1))
                        L[j] = prev + 1;
                    else
                        L[j] = Math.max(L[j], L[j - 1]);
                    prev = temp;
                }
            }
            output.append("Case #").append(++cases).append(": you can visit at most ").append(L[mother.length()]).append(" cities.\n");
        }
	    System.out.print(output);
	}
}
