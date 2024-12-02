import java.io.*;

public class Main {
    static int[] table = {
        0, 0, 1, 1, 3, 1, 3, 1, 3, 3,
        3, 2, 3, 1, 3, 3, 3, 1, 3, 1,
        3, 3, 3, 2, 3, 3, 3, 3, 3, 2,
        3, 1
    };
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            switch(table[n]) {
                case 1:
                    output.append("Perfect: ").append(((long)1 << n - 1) * ((1 << n) - 1)).append("!\n");
                    break;
                case 2:
                    output.append("Given number is prime. But, NO perfect number is available.\n");
                    break;
                case 3:
                    output.append("Given number is NOT prime! NO perfect number is available.\n");
            }
        }
        System.out.print(output);
    }
}
