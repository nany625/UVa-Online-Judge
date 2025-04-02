import java.io.*;
import java.util.*;

public class Main {
    static int MAXN = 10000000;
    static boolean[] isComposite = new boolean[(MAXN >> 2) + 1];
    static ArrayList<Answer> answers = new ArrayList<>();
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    answers.sort(new Comparator<Answer>() {
	        @Override
	        public int compare(Answer a1, Answer a2) {
	            return Integer.compare(a1.n, a2.n);
	        }
	    });
	    answers.get(0).abun = 0;
	    for(int i = 1; i < answers.size(); ++i)
            answers.get(i).abun += answers.get(i - 1).abun - (answers.get(i).n << 1);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
            output.append(n).append(' ').append(n <= 9 ? 0 : answers.get(binarySearch(n)).abun).append('\n');
	    System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 3; n <= MAXN >> 1; n += 2) {
            if(!isComposite[n >> 1]) {
                primes.add(n);
                int tempSum = 1, term = 2;
                while(term * n <= MAXN) {
                    tempSum += term;
                    answers.add(new Answer(term * n, tempSum * (1 + n)));
                    term <<= 1;
                }
            }
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAXN >> 1; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
    
    static int binarySearch(int key) {
        int left = 0, right = answers.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(answers.get(mid).n == key)
                return mid;
            if(answers.get(mid).n < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
}

class Answer {
    int n;
    long abun;
    Answer(int n, long abun) {
        this.n = n;
        this.abun = abun;
    }
}
