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
            String s = st.sval;
            int score = 0, temp = 0, i = 0, len = s.length();
            do {
                if(s.charAt(i) == 'O')
                    score += ++temp;
                else
                    temp = 0;
            } while(++i < len);
            output.append(score).append('\n');
    	}
        System.out.print(output);
	}
}
