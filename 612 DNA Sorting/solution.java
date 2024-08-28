import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int M = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(M-- > 0) {
		    st.nextToken();
		    st.nextToken();
		    int m = (int)st.nval;
		    DNA[] dnas = new DNA[m];
		    for(int i = 0; i < m; ++i) {
		        st.nextToken();
		        dnas[i] = new DNA(st.sval, sortedness(st.sval));
		    }
		    Arrays.sort(dnas, new Comparator<DNA>() {
		        @Override
		        public int compare(DNA d1, DNA d2) {
		            return Integer.compare(d1.sortedness, d2.sortedness);
		        }
		    });
		    for(DNA d : dnas)
		        output.append(d.s).append('\n');
		    if(M > 0)
		        output.append('\n');
        }
		System.out.print(output);
	}
	
	static int sortedness(String s) {
        int count = 0, len = s.length();
        for(int i = 0; i < len - 1; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(s.charAt(i) > s.charAt(j))
                    ++count;
            }
        }
        return count;
    }
}

class DNA {
    String s;
    int sortedness;
    DNA(String s, int sortedness) {
        this.s = s;
        this.sortedness = sortedness;
    }
}
