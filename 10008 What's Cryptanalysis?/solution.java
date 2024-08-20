import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	HashMap<Character, Short> frequencies = new HashMap<>();
    	ArrayList<Character> frequenciesKeys = new ArrayList<>();
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(n-- > 0) {
    	    String text = br.readLine();
    	    int len = text.length();
    	    for(int i = 0; i < len; ++i) {
    	        char ch = text.charAt(i);
    	        if(Character.isLowerCase(ch))
    	            ch = Character.toUpperCase(ch);
    	        if(Character.isUpperCase(ch)) {
    	            if(frequencies.containsKey(ch))
    	                frequencies.replace(ch, (short)(frequencies.get(ch) + 1));
    	            else {
    	                frequencies.put(ch, (short)1);
    	                frequenciesKeys.add(ch);
    	            }
    	        }
    	    }
    	}
    	frequenciesKeys.sort(new Comparator<Character>() {
    	    @Override
    	    public int compare(Character c1, Character c2) {
    	        if(!frequencies.get(c1).equals(frequencies.get(c2)))
    	            return Short.compare(frequencies.get(c2), frequencies.get(c1));
    	        return Character.compare(c1, c2);
    	    }
    	});
    	for(Character c : frequenciesKeys)
    	    output.append(c).append(' ').append(frequencies.get(c)).append('\n');
        bw.write(output.toString());
        bw.flush();
        bw.close();
	}
}
