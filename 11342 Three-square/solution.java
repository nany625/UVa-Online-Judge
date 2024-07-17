import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        HashMap<Integer, Answer> map = new HashMap<>();
        for(short a = 0; a <= 129; ++a) {
            for(short b = a; b <= 158; ++b) {
                for(short c = b; a * a + b * b + c * c <= 50000; ++c) {
                    int sum = a * a + b * b + c * c;
                    if(!map.containsKey(sum))
                        map.put(sum, new Answer(a, b, c));
                }
            }
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int K = (int)st.nval;
            if(map.containsKey(K))
                output.append(map.get(K).a + " " + map.get(K).b + " " + map.get(K).c + "\n");
            else
                output.append("-1\n");
        }
        System.out.print(output);
	}
}

class Answer {
    short a, b, c;
    Answer(short a, short b, short c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
}
