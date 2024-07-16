import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    int[] digits = new int[7];
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.trim().split("\\s+");
            int num = Integer.parseInt(tokens[0], Integer.parseInt(tokens[1])), baseTo = Integer.parseInt(tokens[2]);
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
