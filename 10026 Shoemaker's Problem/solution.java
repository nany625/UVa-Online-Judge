import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int N = (int)st.nval;
            Job[] jobs = new Job[N];
            for(int i = 0; i < N; ++i) {
                jobs[i] = new Job();
                jobs[i].jobNum = i + 1;
                st.nextToken();
                jobs[i].T = (int)st.nval;
                st.nextToken();
                jobs[i].S = (int)st.nval;
            }
            Arrays.sort(jobs, new Comparator<Job>() {
                @Override
                public int compare(Job j1, Job j2) {
                    return Integer.compare(j1.T * j2.S, j1.S * j2.T);
                }
            });
    	    for(int i = 0; i < N; ++i) {
    	        if(i > 0)
    	            output.append(' ');
    	        output.append(jobs[i].jobNum);
    	    }
    	    output.append('\n');
    	    if(cases > 0)
                output.append('\n');
    	}
        System.out.print(output);
	}
}

class Job {
    int jobNum, T, S;
}
