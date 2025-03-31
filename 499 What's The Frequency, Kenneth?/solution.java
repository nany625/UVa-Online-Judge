// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
    	while((line = br.readLine()) != null && !line.isEmpty()) {
    	    short[] frequency = new short[52];
    	    short max = 0;
    	    for(int i = 0; i < line.length(); ++i) {
    	        if(Character.isUpperCase(line.charAt(i)))
    	            max = (short)Math.max(max, ++frequency[line.charAt(i) - 'A']);
    	        else if(Character.isLowerCase(line.charAt(i)))
    	            max = (short)Math.max(max, ++frequency[line.charAt(i) - 'a' + 26]);
    	    }
    	    for(int i = 0; i < 26; ++i) {
    	        if(max == frequency[i])
    	            output.append((char)(i + 'A'));
    	    }
    	    for(int i = 26; i < 52; ++i) {
    	        if(max == frequency[i])
    	            output.append((char)(i - 26 + 'a'));
    	    }
    	    output.append(' ').append(max).append('\n');
		}
        System.out.print(output);
	}
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
    	while((line = br.readLine()) != null && !line.isEmpty()) {
    	    Map<Character, Short> frequency = new TreeMap<>();
    	    short max = 0;
    	    for(int i = 0; i < line.length(); ++i) {
    	        if(Character.isLetter(line.charAt(i))) {
    	            frequency.put(line.charAt(i), (short)(frequency.getOrDefault(line.charAt(i), (short)0) + 1));
					max = (short)Math.max(max, frequency.get(line.charAt(i)));
    	        }
    	    }
    	    for(Character c : frequency.keySet()) {
    	        if(max == frequency.get(c))
    	            output.append(c);
    	    }
    	    output.append(' ').append(max).append('\n');
		}
        System.out.print(output);
	}
}


// #解法三
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
    	while((line = br.readLine()) != null && !line.isEmpty()) {
    	    Map<Character, Short> frequency = new HashMap<>();
    	    ArrayList<Character> frequencyKeys = new ArrayList<>();
    	    short max = 0;
    	    for(int i = 0; i < line.length(); ++i) {
    	        if(Character.isLetter(line.charAt(i))) {
    	            if(frequency.containsKey(line.charAt(i)))
						frequency.replace(line.charAt(i), (short)(frequency.get(line.charAt(i)) + 1));
					else {
						frequency.put(line.charAt(i), (short)1);
						frequencyKeys.add(line.charAt(i));
					}
					max = (short)Math.max(max, frequency.get(line.charAt(i)));
    	        }
    	    }
    	    Collections.sort(frequencyKeys);
    	    for(Character c : frequencyKeys) {
    	        if(max == frequency.get(c))
    	            output.append(c);
    	    }
    	    output.append(' ').append(max).append('\n');
		}
        System.out.print(output);
	}
}
