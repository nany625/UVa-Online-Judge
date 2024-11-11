import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int D = (int)st.nval;
		    output.append("Case #").append(++cases).append(':');
		    short[] sequence = new short[D];
		    boolean sorted = true;
		    for(int i = 0; i < D; ++i) {
		        st.nextToken();
		        output.append(' ').append(sequence[i] = (short)st.nval);
		        if(i > 0 && sequence[i] < sequence[i - 1])
		            sorted = false;
		    }
		    output.append('\n');
		    if(!sorted)
		        output.append("This is not an A-sequence.\n");
		    else
		        output.append(isAsequence(sequence) ? "This is an A-sequence.\n" : "This is not an A-sequence.\n");
		}
        System.out.print(output);
	}
	
	static boolean isAsequence(short[] array) {
        boolean[] subsetSum = new boolean[array[array.length - 1] + 1];
        subsetSum[0] = true;
        for(int i = 0; i < array.length; ++i) {
            if(subsetSum[array[i]])
                return false;
            for(int j = array[array.length - 1]; j >= array[i]; --j)
                subsetSum[j] |= subsetSum[j - array[i]];
        }
        return true;
    }
}
