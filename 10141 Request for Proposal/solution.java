import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int RFP = 0;
		String name = "";
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    st.nextToken();
		    int p = (int)st.nval;
		    if(n == 0 && p == 0)
		        break;
		    if(RFP > 0)
		        output.append('\n');
		    while(n-- > 0)
		        br.readLine();
		    double minR = 0;
		    int maxD = -1;
		    while(p-- > 0) {
		        String s = br.readLine();
		        st.nextToken();
		        double r = st.nval;
		        st.nextToken();
		        int d = (int)st.nval;
		        if(d > maxD) {
		            name = new String(s);
		            minR = r;
		            maxD = d;
		        } else if(d == maxD && r < minR) {
		            name = new String(s);
		            minR = r;
		        }
		        while(d-- > 0)
		            br.readLine();
		    }
		    output.append("RFP #").append(++RFP).append('\n').append(name).append('\n');
		}
		System.out.print(output);
	}
}
