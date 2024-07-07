import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        String keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
        HashMap<Character, Character> decode = new HashMap<>();
        int len = keyboard.length();
        for(int i = 2; i < len; ++i)
            decode.put(keyboard.charAt(i), keyboard.charAt(i - 2));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String message;
        StringBuilder output = new StringBuilder();
        while((message = br.readLine()) != null) {
    	    len = message.length();
    	    for(int i = 0; i < len; ++i) {
    	        if(message.charAt(i) == ' ')
    	            output.append(" ");
    	        else {
    	            if(Character.isUpperCase(message.charAt(i)))
    	                Character.toLowerCase(message.charAt(i));
    	            output.append(decode.get(message.charAt(i)));
    	        }
    	    }
            output.append("\n");
    	}
    	System.out.print(output);
	}
}
