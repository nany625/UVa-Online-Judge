import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int num;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0) {
            output.append("Original number was ").append(num).append('\n');
    		Set<Integer> nums = new HashSet<>();
			do {
    			nums.add(num);
				ArrayList<Integer> digits = new ArrayList<>();
				while(num > 0) {
                    digits.add(num % 10);
                    num /= 10;
                }
                Collections.sort(digits);
                int asc = 0;
                for(Integer digit : digits)
                    asc = 10 * asc + digit;
                int desc = 0;
                for(int i = digits.size() - 1; i >= 0; --i)
                    desc = 10 * desc + digits.get(i);
                num = desc - asc;
                output.append(desc).append(" - ").append(asc).append(" = ").append(num).append('\n');
    		} while(!nums.contains(num));
			output.append("Chain length ").append(nums.size()).append("\n\n");
    	}
        System.out.print(output);
	}
}
