import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
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
            output.append(score + "\n");
    	}
        System.out.print(output);
	}
}
