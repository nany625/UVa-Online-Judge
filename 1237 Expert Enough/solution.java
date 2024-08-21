import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
    	while(T-- > 0) {
    	    if(!firstCase)
    	        output.append('\n');
    	    st.nextToken();
    	    int D = (int)st.nval;
    	    Data[] datas = new Data[D];
    	    for(int i = 0; i < D; ++i) {
    	        st.nextToken();
    	        String M = st.sval;
    	        st.nextToken();
    	        int L = (int)st.nval;
    	        st.nextToken();
    	        datas[i] = new Data(M, L, (int)st.nval);
    	    }
    	    st.nextToken();
    	    int Q = (int)st.nval;
    	    while(Q-- > 0) {
    	        st.nextToken();
    	        int P = (int)st.nval, count = 0, curr = -1;
    	        for(int i = 0; i < D && count <= 1; ++i) {
    	            if(P >= datas[i].L && P <= datas[i].H) {
    	                ++count;
    	                curr = i;
    	            }
    	        }
    	        output.append(count == 1 ? datas[curr].M : "UNDETERMINED").append('\n');
    	    }
    	    firstCase = false;
    	}
        System.out.print(output);
	}
}

class Data {
    String M;
    int L, H;
    Data(String M, int L, int H) {
        this.M = M;
        this.L = L;
        this.H = H;
    }
}
