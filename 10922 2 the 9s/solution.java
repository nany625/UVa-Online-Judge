import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String N;
		StringBuilder output = new StringBuilder();
		while((N = br.readLine()) != null && N.charAt(0) != '0') {
		    int degree = 0, temp = 0;
		    for(int i = 0; i < N.length(); ++i)
                temp += N.charAt(i) - '0';
            while(temp > 9 && temp % 9 == 0) {
                ++degree;
                temp = sumOfDigits(temp);
            }
            degree += temp == 9 ? 1 : 0;
            if(degree == 0)
                output.append(N).append(" is not a multiple of 9.\n");
            else
                output.append(N).append(" is a multiple of 9 and has 9-degree ").append(degree).append(".\n");
		}
		System.out.print(output);
	}
	
	static int sumOfDigits(int n) {
        int result = 0;
        while(n > 0) {
            result += n % 10;
            n /= 10;
        }
        return result;
    }
}
