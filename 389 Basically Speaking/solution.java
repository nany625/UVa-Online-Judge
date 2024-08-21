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
                int i = -1;
    			while(digits[++i] == 0)
    			    output.append(' ');
                while(i < 7) {
    			    output.append(digits[i] > 9 ? (char)(digits[i] - 10 + 'A') : (char)(digits[i] + '0'));
    			    ++i;
    			}
                output.append('\n');
            }
        }
        System.out.print(output);
	}
}
