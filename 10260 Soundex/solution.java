import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_WORD) {
            char[] word = st.sval.toCharArray();
            for(int i = 0; i < word.length; ++i) {
                switch(word[i]) {
                    case 'B':
                    case 'F':
                    case 'P':
                    case 'V':
                        word[i] = '1';
                        break;
                    case 'C':
                    case 'G':
                    case 'J':
                    case 'K':
                    case 'Q':
                    case 'S':
                    case 'X':
                    case 'Z':
                        word[i] = '2';
                        break;
                    case 'D':
                    case 'T':
                        word[i] = '3';
                        break;
                    case 'L':
                        word[i] = '4';
                        break;
                    case 'M':
                    case 'N':
                        word[i] = '5';
                        break;
                    case 'R':
                        word[i] = '6';
                }
            }
            if(Character.isDigit(word[0]))
                output.append(word[0]);
            for(int i = 1; i < word.length; ++i) {
                if(Character.isDigit(word[i]) && word[i] != word[i - 1])
                    output.append(word[i]);
            }
            output.append('\n');
        }
        System.out.print(output);
	}
}
