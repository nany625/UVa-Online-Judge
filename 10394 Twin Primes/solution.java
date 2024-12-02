import java.io.*;

public class Main {
    static int MAX_NUM = 20000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static int[] twinPrimes = new int[100000];
    static int count = 1;
    public static void main(String[] args) throws IOException {
        twinPrimes[0] = 3;
        for(int i = 5; count < 100000; i += 4) {
            if(!isComposite[i] && i <= 4472) {
                for(int j = i * i; j <= MAX_NUM; j += i << 1)
                    isComposite[j] = true;
            }
            i += 2;
            if(!isComposite[i] && i <= 4472) {
                for(int j = i * i; j <= MAX_NUM; j += i << 1)
                    isComposite[j] = true;
            }
            if(!isComposite[i - 2] && !isComposite[i])
                twinPrimes[count++] = i - 2;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int S = (int)st.nval - 1;
            output.append('(').append(twinPrimes[S]).append(", ").append(twinPrimes[S] + 2).append(")\n");
        }
        System.out.print(output);
    }
}
