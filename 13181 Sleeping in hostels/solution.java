import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String bed;
        StringBuilder output = new StringBuilder();
        while((bed = br.readLine()) != null) {
            int len = bed.length(), prev = 0;
            while(prev < len && bed.charAt(prev) != 'X')
                ++prev;
            int curr = prev + 1, max = prev - 1;
            while(curr < len) {
                if(bed.charAt(curr) == 'X') {
                    max = Math.max(max, curr - prev - 2 >> 1);
                    prev = curr;
                }
                ++curr;
            }
            max = Math.max(max, len - prev - 2);
            output.append(max).append('\n');
        }
        System.out.print(output);
	}
}
