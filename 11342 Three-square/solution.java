import java.io.*;

public class Main {
    static int MAX_NUM = 50000;
    static Answer[] answers = new Answer[MAX_NUM + 1];
    static boolean[] table = new boolean[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
        for(short a = 0; a <= 129; ++a) {
            for(short b = a; b <= 158; ++b) {
                int sum;
                for(short c = b; (sum = a * a + b * b + c * c) <= MAX_NUM; ++c) {
                    if(!table[sum]) {
                        table[sum] = true;
                        answers[sum] = new Answer(a, b, c);
                    }
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int K = (int)st.nval;
            if(table[K])
                output.append(answers[K].a).append(' ').append(answers[K].b).append(' ').append(answers[K].c).append('\n');
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
