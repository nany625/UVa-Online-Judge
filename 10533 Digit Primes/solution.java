import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[1000000];
    static short[] dpCount = new short[1000000];
	public static void main(String[] args) throws IOException {
	    isComposite[0] = isComposite[1] = true;
	    for(int i = 2; i < 1000000; ++i) {
	        dpCount[i] = dpCount[i - 1];
	        if(i <= 999 && !isComposite[i]) {
    	        for(int j = i * i; j < 1000000; j += i)
    	            isComposite[j] = true;
	        }
	        if(!isComposite[i] && !isComposite[sumOfDigits(i)])
	            ++dpCount[i];
	    }
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
		    int t1 = (int)st.nval;
		    st.nextToken();
		    int t2 = (int)st.nval;
			output.append(dpCount[t2] - dpCount[t1 - 1] + "\n");
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
}
