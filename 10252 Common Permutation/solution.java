import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String a, b;
        StringBuilder output = new StringBuilder();
        while((a = br.readLine()) != null && (b = br.readLine()) != null) {
            short[] frequencya = new short[26], frequencyOutput = new short[26];
            int len = a.length();
            for(int i = 0; i < len; ++i)
                ++frequencya[a.charAt(i) - 'a'];
            len = b.length();
            for(int i = 0; i < len; ++i) {
                if(frequencyOutput[b.charAt(i) - 'a'] < frequencya[b.charAt(i) - 'a'])
                    ++frequencyOutput[b.charAt(i) - 'a'];
            }
            for(int i = 0; i < 26; ++i) {
                while(frequencyOutput[i]-- > 0)
                    output.append((char)('a' + i));
            }
            output.append("\n");
        }
        System.out.print(output);
	}
}
