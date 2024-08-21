import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            if(!firstCase)
                output.append('\n');
            st.nextToken();
            String alphaKey = st.sval;
            st.nextToken();
            int numericalKey = (int)st.nval;
            st.nextToken();
            int messages = (int)st.nval;
            boolean[] L = new boolean[26];
            int alphaKeyLen = alphaKey.length();
            for(int i = 0; i < alphaKeyLen; ++i)
                L[alphaKey.charAt(i) - 'A'] = true;
            while(messages-- > 0) {
                String cipheredtext = br.readLine();
                StringBuilder plaintext = new StringBuilder();
                int m = 0, curr = 0, len = cipheredtext.length();
                boolean error = false;
                while(curr < len && !error) {
                    if(!Character.isUpperCase(cipheredtext.charAt(curr)))
                        plaintext.append(cipheredtext.charAt(curr++));
                    else {
                        if(curr < len - 2 && Character.isUpperCase(cipheredtext.charAt(curr + 1)) && Character.isUpperCase(cipheredtext.charAt(curr + 2))) {
                            if(cipheredtext.charAt(curr) == alphaKey.charAt(m) && cipheredtext.charAt(curr + 2) == alphaKey.charAt((m + 1) % alphaKeyLen)) {
                                char deciphChar = deciph(cipheredtext.charAt(curr + 1), numericalKey);
                                if(L[deciphChar - 'A']) {
                                    plaintext.append(deciphChar);
                                    m = ++m % alphaKeyLen;
                                    curr += 3;
                                } else
                                    error = true;
                            } else {
                                char deciphChar = deciph(cipheredtext.charAt(curr), numericalKey);
                                if(!L[deciphChar - 'A']) {
                                    plaintext.append(deciphChar);
                                    ++curr;
                                } else
                                    error = true;
                            }
                        } else {
                            char deciphChar = deciph(cipheredtext.charAt(curr), numericalKey);
                            if(!L[deciphChar - 'A']) {
                                plaintext.append(deciphChar);
                                ++curr;
                            } else
                                error = true;
                        }
                    }
                }
                if(!error)
                    output.append(plaintext).append('\n');
                else
                    output.append("error in encryption\n");
            }
            firstCase = false;
        }
	    System.out.print(output);
	}
	
	static char deciph(char ch, int N) {
	    return (char)((ch - 'A' + 26 - N) % 26 + 'A');
	}
}
