import java.io.*;

public class Main {
    static int MAX_NUM = 999999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static short[] dpCount = new short[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    isComposite[0] = isComposite[1] = true;
	    eratosthenesSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
		    int t1 = (int)st.nval;
		    st.nextToken();
		    int t2 = (int)st.nval;
			output.append(dpCount[t2] - dpCount[t1 - 1]).append('\n');
    	}
        System.out.print(output);
	}
	
	static int sumOfDigits(int n) {
        int result = 0;
        while(n > 0) {
            result += n % 10;
            n /= 10;
        }
        return result;
    }
    
    static void eratosthenesSieve() {
	    isComposite[0] = isComposite[1] = true;
        for(int n = 2; n <= MAX_NUM; ++n) {
            dpCount[n] = dpCount[n - 1];
            if(n <= 999 && !isComposite[n]) {
                for(int i = n * n; i <= MAX_NUM; i += n)
                    isComposite[i] = true;
            }
            if(!isComposite[n] && !isComposite[sumOfDigits(n)])
	            ++dpCount[n];
        }
    }
}
