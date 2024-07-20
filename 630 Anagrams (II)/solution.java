import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int T = (int)st.nval;
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    if(!firstCase)
		        output.append("\n");
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
		        output.append("Anagrams for: " + test + "\n");
		        char[] temp = test.toCharArray();
		        Arrays.sort(temp);
		        String sortedTest = new String(temp);
		        int count = 0;
		        for(Anagram a : anagrams) {
		            if(sortedTest.equals(a.sortedWord))
		                output.append("  " + (++count) + ") " + a.word + "\n");
		        }
		        if(count == 0)
		            output.append("No anagrams for: " + test + "\n");
		    }
		    firstCase = false;
		}
		System.out.print(output);
	}
}

class Anagram {
    String word, sortedWord;
}
