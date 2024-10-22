import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            short[] array = new short[N];
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                array[i] = (short)st.nval;
                if(array[i] == 0) {
                    --i;
                    --N;
                }
            }
            int max = array[0], curr = array[0], start = 0, first = 0, last = 0, length = 1;
            for(int i = 1; i < N; ++i) {
                if(array[i] > curr + array[i]) {
                    curr = array[i];
                    first = i;
                } else {
                    curr += array[i];
                    last = i;
                }
                if(max < curr) {
                    max = curr;
                    length = last - (start = first) + 1;
                }
            }
            if(N == 0)
                output.append("0\n");
            else {
                for(int i = start; i < start + length - 1; ++i)
                    output.append(array[i]).append(' ');
                output.append(array[start + length - 1]).append('\n');
            }
        }
	    System.out.print(output);
	}
}
