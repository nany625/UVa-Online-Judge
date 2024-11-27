import java.io.*;

public class Main {
    static int[] primes = {2, 3, 5, 7, 13, 17};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();
        String[] p = br.readLine().split(",");
        StringBuilder output = new StringBuilder();
        for(String s : p) {
            int num = Integer.parseInt(s);
            boolean perfect = false;
            for(int i = 0; i < 6 && !perfect; ++i) {
                if(primes[i] == num)
                    perfect = true;
            }
            output.append(perfect ? "Yes\n" : "No\n");
        }
        System.out.print(output);
    }
}
