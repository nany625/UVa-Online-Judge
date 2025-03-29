import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
		    st.nextToken();
		    int M = (int)st.nval;
		    output.append(N).append(' ').append(M).append('\n');
		    Data[] datas = new Data[N];
		    for(int i = 0; i < N; ++i) {
		        st.nextToken();
		        int number = (int)st.nval;
		        datas[i] = new Data(number, number % M);
		    }
		    Arrays.sort(datas, new Comparator<Data>() {
		        @Override
		        public int compare(Data d1, Data d2) {
		            if(d1.mod != d2.mod)
		                return d1.mod - d2.mod;
		            int isOddd1 = (int)Math.abs(d1.number & 1);
		            int isOddd2 = (int)Math.abs(d2.number & 1);
		            if(isOddd1 + isOddd2 == 1)
		                return isOddd1 == 1 ? -1 : 1;
		            if(isOddd1 == 1)
		                return Integer.compare(d2.number, d1.number);
		            return Integer.compare(d1.number, d2.number);
		        }
		    });
		    for(Data d : datas)
		        output.append(d.number).append('\n');
		}
		System.out.println(output + "0 0");
	}
}

class Data {
    int number, mod;
    Data(int number, int mod) {
        this.number = number;
        this.mod = mod;
    }
}
