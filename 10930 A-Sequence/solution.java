import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
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
		        output.append(isAsequence(sequence, D) ? "This is an A-sequence.\n" : "This is not an A-sequence.\n");
		}
        System.out.print(output);
	}
	
	static boolean isAsequence(short[] array, int size) {
        boolean[] subsetSum = new boolean[array[size - 1] + 1];
        subsetSum[0] = true;
        for(int i = 0; i < size; ++i) {
            if(subsetSum[array[i]])
                return false;
            for(int j = array[size - 1]; j >= array[i]; --j)
                subsetSum[j] |= subsetSum[j - array[i]];
        }
        return true;
    }
}
