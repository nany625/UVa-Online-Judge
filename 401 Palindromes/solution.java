import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	        String Characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    	    String Reverses = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";
    	    HashMap<Character, Character> map = new HashMap<>();
    	    for(int i = 0; i < 35; ++i)
    	        map.put(Characters.charAt(i), Reverses.charAt(i));
            String s;
            while((s = br.readLine()) != null) {
    	        int len = s.length();
    	        boolean isMirror = true;
    	        for(int i = 0; i < (len + 1) / 2 && isMirror; ++i) {
    	            if(map.get(s.charAt(i)) != s.charAt(len - 1 - i))
                        isMirror = false;
                }
    	        String reversed = new StringBuilder(s).reverse().toString();
    	        if(s.equals(reversed) && isMirror)
    	            System.out.println(s + " -- is a mirrored palindrome.\n");
    	        else if(s.equals(reversed))
    	            System.out.println(s + " -- is a regular palindrome.\n");
    	        else if(isMirror)
    	            System.out.println(s + " -- is a mirrored string.\n");
    	        else
    	            System.out.println(s + " -- is not a palindrome.\n");
            }
        } catch(IOException e) {};
	}
}
