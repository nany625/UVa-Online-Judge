import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    Frequency[] frequencies = new Frequency[26];
    	for(int i = 0; i < 26; ++i)
    	    frequencies[i] = new Frequency((char)('A' + i), (short)0);
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringBuilder output = new StringBuilder();
    	while(n-- > 0) {
    	    String text = br.readLine();
    	    int len = text.length();
    	    for(int i = 0; i < len; ++i) {
    	        if(Character.isUpperCase(text.charAt(i)))
    	            ++frequencies[text.charAt(i) - 'A'].count;
    	        else if(Character.isLowerCase(text.charAt(i)))
    	            ++frequencies[text.charAt(i) - 'a'].count;
    	    }
    	}
    	Arrays.sort(frequencies, new Comparator<Frequency>() {
    	    @Override
    	    public int compare(Frequency f1, Frequency f2) {
    	        if(f1.count != f2.count)
    	            return f2.count - f1.count;
    	        return f1.alpha - f2.alpha;
    	    }
    	});
    	for(int i = 0; i < 26 && frequencies[i].count > 0; ++i)
    	    output.append(frequencies[i].alpha + " " + frequencies[i].count + "\n");
        System.out.print(output);
	}
}

class Frequency {
    char alpha;
    short count;
    Frequency(char alpha, short count) {
        this.alpha = alpha;
        this.count = count;
    }
}
