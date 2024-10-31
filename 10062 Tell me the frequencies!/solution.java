import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while((text = br.readLine()) != null) {
            if(!firstCase)
                output.append('\n');
            HashMap<Character, Short> frequencies = new HashMap<>();
            ArrayList<Character> frequenciesKeys = new ArrayList<>();
            for(int i = 0; i < text.length(); ++i) {
                if(frequencies.containsKey(text.charAt(i)))
                    frequencies.replace(text.charAt(i), (short)(frequencies.get(text.charAt(i)) + 1));
                else {
                    frequencies.put(text.charAt(i), (short)1);
                    frequenciesKeys.add(text.charAt(i));
                }
            }
            frequenciesKeys.sort(new Comparator<Character>() {
                @Override
                public int compare(Character c1, Character c2) {
                    if(!frequencies.get(c1).equals(frequencies.get(c2)))
                        return Short.compare(frequencies.get(c1), frequencies.get(c2));
                    return Character.compare(c2, c1);
                }
            });
            for(Character c : frequenciesKeys)
                output.append((int)c).append(' ').append(frequencies.get(c)).append('\n');
            firstCase = false;
        }
        System.out.print(output);
	}
}
