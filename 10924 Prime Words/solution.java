import java.io.*;

public class Main {
    static int MAX_NUM = 1040;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
		eratosthenesSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
            String L = st.sval;
            int sum = 0;
            for(int i = 0; i < L.length(); ++i) {
                if(Character.isUpperCase(L.charAt(i)))
                    sum += L.charAt(i) - 'A' + 27;
                else if(Character.isLowerCase(L.charAt(i)))
                    sum += L.charAt(i) - 'a' + 1;
            }
	        output.append(isComposite[sum] ? "It is not a prime word.\n" : "It is a prime word.\n");
        }
        System.out.print(output);
	}
	
	static void eratosthenesSieve() {
        for(short n = 2; n <= MAX_NUM; ++n) {
            if(n <= 32 && !isComposite[n]) {
                for(int i = n * n; i <= MAX_NUM; i += n)
                    isComposite[i] = true;
            }
        }
    }
}
