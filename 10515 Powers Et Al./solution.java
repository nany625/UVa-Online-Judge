import java.io.*;

public class Main {
    static String[] lastDigit = {"6248", "1397", "64", "", "", "1793", "6842", "19"};
    static int[] cycle = {4, 4, 2, 0, 0, 4, 4, 2};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.split("\\s+");
            if(tokens[0].charAt(0) == '0' && tokens[1].charAt(0) == '0')
                break;
            int base = tokens[0].charAt(tokens[0].length() - 1) - '0';
            if(base == 0)
                output.append("0\n");
            else if(base == 1 || tokens[1].charAt(0) == '0')
                output.append("1\n");
            else if(base == 5 || base == 6)
                output.append(base).append('\n');
            else {
                int len = tokens[1].length(), N;
                if(len == 1)
                    N = tokens[1].charAt(0) - '0';
                else
                    N = 10 * (tokens[1].charAt(len - 2) - '0') + tokens[1].charAt(len - 1) - '0';
                output.append(lastDigit[base - 2].charAt(N % cycle[base - 2])).append('\n');
            }
        }
        System.out.print(output);
	}
}
