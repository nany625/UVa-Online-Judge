import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    char[] nucleotides = {'A', 'C', 'G', 'T'};
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(T-- > 0) {
    	    st.nextToken();
            int m = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            String[] DNA = new String[m];
            for(int i = 0; i < m; ++i) {
                st.nextToken();
                DNA[i] = st.sval;
            }
            int dist = m * n;
            for(int i = 0; i < n; ++i) {
                int[] nucleotidesCount = new int[4];
                for(int j = 0; j < m; ++j) {
                    if(DNA[j].charAt(i) == 'A')
                        ++nucleotidesCount[0];
                    else if(DNA[j].charAt(i) == 'C')
                        ++nucleotidesCount[1];
                    else if(DNA[j].charAt(i) == 'G')
                        ++nucleotidesCount[2];
                    else if(DNA[j].charAt(i) == 'T')
                        ++nucleotidesCount[3];
                }
                int max = 0, temp = -1;
                for(int j = 0; j < 4; ++j) {
                    if(max < nucleotidesCount[j]) {
                        max = nucleotidesCount[j];
                        temp = j;
                    }
                }
                output.append(nucleotides[temp]);
                dist -= max;
            }
            output.append("\n" + dist + "\n");
    	}
        System.out.print(output);
	}
}
