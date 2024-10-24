import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    String Characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
        String Reverses = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";
        HashMap<Character, Character> map = new HashMap<>();
        for(int i = 0; i < 35; ++i)
            map.put(Characters.charAt(i), Reverses.charAt(i));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        StringBuilder output = new StringBuilder();
        while((s = br.readLine()) != null) {
	        int len = s.length();
            boolean isMirror = true;
	        for(int i = 0; i < len + 1 >> 1 && isMirror; ++i)
                isMirror = map.get(s.charAt(i)) == s.charAt(len - 1 - i);
            String reversed = new StringBuilder(s).reverse().toString();
	        if(s.equals(reversed) && isMirror)
                output.append(s).append(" -- is a mirrored palindrome.\n\n");
	        else if(s.equals(reversed))
                output.append(s).append(" -- is a regular palindrome.\n\n");
            else if(isMirror)
                output.append(s).append(" -- is a mirrored string.\n\n");
            else
                output.append(s).append(" -- is not a palindrome.\n\n");
        }
        System.out.print(output);
	}
}
