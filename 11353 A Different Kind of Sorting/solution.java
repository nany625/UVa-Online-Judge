import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 2000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static Answer[] answers = new Answer[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    Arrays.sort(answers, new Comparator<Answer>() {
	        @Override
	        public int compare(Answer a1, Answer a2) {
	            return Integer.compare(a1.pfCount, a2.pfCount);
	        }
	    });
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0, n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
		    output.append("Case ").append(++cases).append(": ").append(answers[n].n).append('\n');
		System.out.print(output);
	}
	
	static void eulerSieve() {
	    answers[0] = new Answer(0, 0);
        answers[1] = new Answer(1, 0);
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n]) {
                primes.add(n);
                answers[n] = new Answer(n, 1);
            }
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                answers[temp] = new Answer(temp, answers[primes.get(i)].pfCount + answers[n].pfCount);
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}

class Answer {
    int n, pfCount;
    Answer(int n, int pfCount) {
        this.n = n;
        this.pfCount = pfCount;
    }
}
