import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(T-- > 0) {
    	    st.nextToken();
    	    int D = (int)st.nval;
    	    Data[] datas = new Data[D];
    	    for(int i = 0; i < D; ++i) {
                datas[i] = new Data();
    	        st.nextToken();
    	        datas[i].M = st.sval;
    	        st.nextToken();
    	        datas[i].L = (int)st.nval;
    	        st.nextToken();
    	        datas[i].H = (int)st.nval;
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
    	    if(T > 0)
                output.append('\n');
    	}
        System.out.print(output);
	}
}

class Data {
    String M;
    int L, H;
}
