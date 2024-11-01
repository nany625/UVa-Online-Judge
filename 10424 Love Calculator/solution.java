import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String name1, name2;
		StringBuilder output = new StringBuilder();
		while((name1 = br.readLine()) != null && (name2 = br.readLine()) != null) {
		    int sum1 = sum(name1), sum2 = sum(name2);
            int sumOfDigits1 = sumOfDigits(sum1), sumOfDigits2 = sumOfDigits(sum2);
            if(sumOfDigits1 > sumOfDigits2) {
                int temp = sumOfDigits1;
                sumOfDigits1 = sumOfDigits2;
                sumOfDigits2 = temp;
            }
            output.append(String.format("%.2f %%\n", 100.0 * sumOfDigits1 / sumOfDigits2));
		}
		System.out.print(output);
	}
	
	static int sum(String s) {
        int result = 0;
        for(int i = 0; i < s.length(); ++i) {
            if(Character.isUpperCase(s.charAt(i)))
                result += s.charAt(i) - 'A' + 1;
            else if(Character.isLowerCase(s.charAt(i)))
                result += s.charAt(i) - 'a' + 1;
        }
        return result;
    }
    
    static int sumOfDigits(int n) {
        int result = 0;
        while(n > 0) {
            result += n % 10;
            n /= 10;
        }
        return result > 9 ?  sumOfDigits(result) : result;
    }
}
