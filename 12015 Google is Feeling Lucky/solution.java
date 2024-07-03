import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Webpage[] webpages = new Webpage[10];
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
			output.append("Case #" + i + ":\n");
			short max = 0;
			for(int j = 0; j < 10; ++j) {
			    st.nextToken();
			    String url = st.sval;
			    st.nextToken();
			    webpages[j] = new Webpage(url, (short)st.nval);
			    max = (short)Math.max(max, webpages[j].relevance);
			}
			for(Webpage w : webpages) {
			    if(w.relevance == max)
			        output.append(w.url + "\n");
			}
		}
        System.out.print(output);
    }
}

class Webpage {
    String url;
    short relevance;
    Webpage(String url, short relevance) {
        this.url = url;
        this.relevance = relevance;
    }
}
