import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<String> sentences = new ArrayList<>();
        String sentence;
        int maxLen = 0;
        StringBuilder output = new StringBuilder();
        while((sentence = br.readLine()) != null && !sentence.isEmpty()) {
            maxLen = Math.max(maxLen, sentence.length());
            sentences.add(sentence);
        }
        for(int i = 0; i < maxLen; ++i) {
            for(int j = sentences.size() - 1; j >= 0; --j)
                output.append(i < sentences.get(j).length() ? sentences.get(j).charAt(i) : " ");
            output.append("\n");
        }
        System.out.print(output);
	}
}
