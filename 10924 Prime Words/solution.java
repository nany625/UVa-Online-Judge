import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[1041];
	public static void main(String[] args) throws IOException {
		for(int i = 2; i <= 1040; ++i) {
            if(!isComposite[i] && i <= 32) {
                for(int j = i * i; j <= 1040; j += i)
                    isComposite[j] = true;
            }
        }
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
            String L = st.sval;
            int len = L.length(), sum = 0;
            for(int i = 0; i < len; ++i) {
                if(Character.isUpperCase(L.charAt(i)))
                    sum += L.charAt(i) - 'A' + 27;
                else if(Character.isLowerCase(L.charAt(i)))
                    sum += L.charAt(i) - 'a' + 1;
            }
	        output.append(isComposite[sum] ? "It is not a prime word.\n" : "It is a prime word.\n");
        }
        System.out.print(output);
	}
}
