import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String bed;
        StringBuilder output = new StringBuilder();
        while((bed = br.readLine()) != null) {
            int prev = 0;
            while(prev < bed.length() && bed.charAt(prev) != 'X')
                ++prev;
            int curr = prev + 1, max = prev - 1;
            while(curr < bed.length()) {
                if(bed.charAt(curr) == 'X') {
                    max = Math.max(max, curr - prev - 2 >> 1);
                    prev = curr;
                }
                ++curr;
            }
            max = Math.max(max, bed.length() - prev - 2);
            output.append(max).append('\n');
        }
        System.out.print(output);
	}
}
