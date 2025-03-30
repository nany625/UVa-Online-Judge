// #解法一
import java.io.*;

public class Main {
    static Webpage[] webpages = new Webpage[10];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
			output.append("Case #").append(i).append(":\n");
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
			        output.append(w.url).append('\n');
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

// #解法二
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
			output.append("Case #").append(i).append(":\n");
			ArrayList<String> candidates = new ArrayList<>();
			int count = 0, lines = 10;
			short max = 0;
			while(lines-- > 0) {
			    st.nextToken();
			    String url = st.sval;
			    st.nextToken();
			    if(max < (short)st.nval) {
			        max = (short)st.nval;
			        candidates.add(url);
			        count = 1;
			    } else if(max == (short)st.nval) {
			        candidates.add(url);
			        ++count;
			    }
			}
			for(int j = candidates.size() - count; j < candidates.size(); ++j)
			    output.append(candidates.get(j)).append('\n');
		}
        System.out.print(output);
    }
}
