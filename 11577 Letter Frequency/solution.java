import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            String s = br.readLine();
            int[] count = new int[26];
            for(int i = 0; i < s.length(); ++i) {
                if(Character.isUpperCase(s.charAt(i)))
                    ++count[s.charAt(i) - 'A'];
                else if(Character.isLowerCase(s.charAt(i)))
                    ++count[s.charAt(i) - 'a'];
            }
            int max = 0;
            for(Integer i : count)
                max = Math.max(max, i);
            for(int i = 0; i < 26; ++i) {
                if(max == count[i])
                    output.append((char)('a' + i));
            }
            output.append('\n');
    	}
        System.out.print(output);
	}
}
