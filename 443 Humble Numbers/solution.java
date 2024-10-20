import java.io.*;
import java.util.*;

public class Main {
    static int[] humbleNumbers = new int[5842];
    static int size = 0;
    public static void main(String[] args) throws IOException {
        long temp = 1;
        while(temp <= 2000000000 && size < 5842) {
            long a = 1;
            while(temp <= 2000000000 && size < 5842) {
                long b = 1;
                while(temp <= 2000000000 && size < 5842) {
                    long c = 1;
                    while(temp <= 2000000000 && size < 5842) {
                        humbleNumbers[size++] = (int)temp;
                        temp *= 7;
                        c *= 7;
                    }
                    temp /= c;
                    temp *= 5;
                    b *= 5;
                }
                temp /= b;
                temp *= 3;
                a *= 3;
            }
            temp /= a;
            temp <<= 1;
        }
        Arrays.sort(humbleNumbers);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        ;
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            if(n % 100 >= 11 && n % 100 <= 13)
                output.append("The ").append(n).append("th humble number is ").append(humbleNumbers[n - 1]).append(".\n");
            else if(n % 10 == 1)
                output.append("The ").append(n).append("st humble number is ").append(humbleNumbers[n - 1]).append(".\n");
            else if(n % 10 == 2)
                output.append("The ").append(n).append("nd humble number is ").append(humbleNumbers[n - 1]).append(".\n");
            else if(n % 10 == 3)
                output.append("The ").append(n).append("rd humble number is ").append(humbleNumbers[n - 1]).append(".\n");
            else
                output.append("The ").append(n).append("th humble number is ").append(humbleNumbers[n - 1]).append(".\n");
        }
        System.out.print(output);
    }
}
