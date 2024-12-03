import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
		    String realName = st.sval;
		    st.nextToken();
		    String gameName = st.sval;
		    if(realName.length() == gameName.length()) {
		        boolean same = true;
		        for(int i = 0; i < realName.length() && same; ++i) {
		            if(isVowel(realName.charAt(i)) != isVowel(gameName.charAt(i)) || (!isVowel(realName.charAt(i)) && realName.charAt(i) != gameName.charAt(i))) {
    	                output.append("No\n");
    	                same = false;
    	            }
		        }
		        if(same)
		            output.append("Yes\n");
		    } else
		        output.append("No\n");
		}
		System.out.print(output);
	}
	
	static boolean isVowel(char ch) {
	    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
	}
}
