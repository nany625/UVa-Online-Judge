import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[2001];
    static short[] primes = new short[303];
    static int count = 0;
	public static void main (String[] args) throws IOException {
		isComposite[0] = isComposite[1] = true;
		for(short i = 2; count < 303; ++i) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 44) {
                    for(int j = i * i; j <= 2000; j += i)
                        isComposite[j] = true;
                }
            }
        }
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    output.append("Case ").append(i).append(": ");
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
                if(!isComposite[frequency[j]]) {
                    if(j < 10)
                        output.append((char)('0' + j));
                    else if(j < 36)
                        output.append((char)('A' + j - 10));
                    else
                        output.append((char)('a' + j - 36));
                    empty = false;
                }
            }
            output.append(empty ? "empty\n" : '\n');
        }
		System.out.print(output);
	}
}
