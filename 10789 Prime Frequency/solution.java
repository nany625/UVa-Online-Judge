import java.io.*;

public class Main {
    static short[] primes = new short[295];
    static int count = 1;
    static boolean[] table = new boolean[1937];
	public static void main (String[] args) throws IOException {
		primes[0] = 2;
		table[2] = true;
		for(short i = 3; count < 295; i += 2) {
            if(isPrime(i)) {
                primes[count++] = i;
                table[i] = true;
            }
        }
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    output.append("Case " + i + ": ");
		    String s = br.readLine();
		    short[] frequency = new short[62];
		    int len = s.length();
		    for(int j = 0; j < len; ++j) {
                if(Character.isDigit(s.charAt(j)))
                    ++frequency[s.charAt(j) - '0'];
                else if(Character.isUpperCase(s.charAt(j)))
                    ++frequency[s.charAt(j) - 'A' + 10];
                else if(Character.isLowerCase(s.charAt(j)))
                    ++frequency[s.charAt(j) - 'a' + 36];
            }
            boolean empty = true;
            for(int j = 0; j < 62; ++j) {
                if(table[frequency[j]]) {
                    if(j < 10)
                        output.append((char)('0' + j));
                    else if(j < 36)
                        output.append((char)('A' + j - 10));
                    else
                        output.append((char)('a' + j - 36));
                    empty = false;
                }
            }
            output.append(empty ? "empty\n" : "\n");
        }
		System.out.print(output);
	}
	
	static boolean isPrime(short n) {
        short limit = (short)Math.sqrt(n);
        for(int i = 1; i < count && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
}
