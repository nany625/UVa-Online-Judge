import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        String keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
        int len = keyboard.length();
        HashMap<Character, Character> decode = new HashMap<>();
        for(int i = 1; i < len; ++i)
            decode.put(keyboard.charAt(i), keyboard.charAt(i - 1));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text;
        StringBuilder output = new StringBuilder();
        while((text = br.readLine()) != null) {
            for(int i = 0; i < text.length(); ++i) {
                if(decode.containsKey(text.charAt(i)))
                    output.append(decode.get(text.charAt(i)));
                else
                    output.append(text.charAt(i));
            }
            output.append('\n');
		}
        System.out.print(output);
	}
}
