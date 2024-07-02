import java.io.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String s;
            while((s = br.readLine()) != null) {
    		    s.trim();
    		    int count = 0, i = 0, len = s.length();
    			while(i < len) {
    				if(Character.isLetter(s.charAt(i))) {
    					int j = i + 1;
    					while(j < len && Character.isLetter(s.charAt(j)))
    						++j;
    					++count;
    					i = j;
    				}
    				++i;
    			}
    			System.out.println(count);
    		}
        } catch(IOException e) {};
	}
}
