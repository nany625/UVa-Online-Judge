import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int N = (int)st.nval;
		    Anagram[] anagrams = new Anagram[N];
		    for(int i = 0; i < N; ++i) {
		        anagrams[i] = new Anagram();
		        st.nextToken();
		        anagrams[i].word = st.sval;
		        char[] temp = anagrams[i].word.toCharArray();
		        Arrays.sort(temp);
		        anagrams[i].sortedWord = new String(temp);
		    }
		    String test;
		    while(st.nextToken() == StreamTokenizer.TT_WORD && !(test = st.sval).equals("END")) {
		        output.append("Anagrams for: ").append(test).append('\n');
		        char[] temp = test.toCharArray();
		        Arrays.sort(temp);
		        String sortedTest = new String(temp);
		        int count = 0;
		        for(Anagram a : anagrams) {
		            if(sortedTest.equals(a.sortedWord))
		                output.append("  ").append(++count).append(") ").append(a.word).append('\n');
		        }
		        if(count == 0)
		            output.append("No anagrams for: ").append(test).append('\n');
		    }
		    if(T > 0)
		        output.append('\n');
		}
		System.out.print(output);
	}
}

class Anagram {
    String word, sortedWord;
}
