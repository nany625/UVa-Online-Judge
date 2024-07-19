import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            int N = (int)st.nval;
            HashMap<String, Integer> subject = new HashMap<>();
            while(N-- > 0) {
                st.nextToken();
                String name = st.sval;
                st.nextToken();
                subject.put(name, (int)st.nval);
            }
            st.nextToken();
            int days = (int)st.nval;
            st.nextToken();
            if(!subject.containsKey(st.sval))
                output.append("Case " + i + ": Do your own homework!\n");
            else {
                if(days >= subject.get(st.sval))
                    output.append("Case " + i + ": Yesss\n");
                else if(days + 5 < subject.get(st.sval))
                    output.append("Case " + i + ": Do your own homework!\n");
                else
                    output.append("Case " + i + ": Late\n");
            }
        }
        System.out.print(output);
	}
}
