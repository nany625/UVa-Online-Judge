import java.util.*;

public class Main {
	public static void main(String[] args) {
	    int[] digits = new int[7];
	    Scanner sc = new Scanner(System.in);
        StringBuilder output = new StringBuilder();
        while(sc.hasNext()) {
            String number = sc.next();
            int num = Integer.parseInt(number, sc.nextInt());
            int baseTo = sc.nextInt();
            if(num == 0) {
                output.append("      0\n");
                continue;
            }
            for(int i = 6; i >= 0; --i) {
                digits[i] = num % baseTo;
                num /= baseTo;
            }
            if(num > 0)
                output.append("  ERROR\n");
            else {
                boolean leadingZero = true;
                for(int i = 0; i < 7; ++i) {
                    if(digits[i] == 0 && leadingZero)
                        output.append(" ");
                    else {
                        leadingZero = false;
                        if(digits[i] > 9)
                            output.append((char)(digits[i] - 10 + 'A'));
                        else
                            output.append(digits[i]);
                    }
                }
                output.append("\n");
            }
        }
        System.out.print(output);
	}
}
