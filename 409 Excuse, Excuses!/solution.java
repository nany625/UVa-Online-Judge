import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int set = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int K = (int)st.nval;
            st.nextToken();
            int E = (int)st.nval;
            output.append("Excuse Set #").append(++set).append('\n');
            ArrayList<String> keywords = new ArrayList<>();
    	    while(K-- > 0) {
    	        st.nextToken();
    	        String keyword = st.sval;
    	        if(keyword.equals(keyword.toLowerCase()))
    	            keywords.add(keyword);
    	    }
    	    Collections.sort(keywords);
    	    Excuse[] excuses = new Excuse[E];
    	    short max = 0;
    	    for(int i = 0; i < E; ++i) {
    	        excuses[i] = new Excuse(br.readLine(), (short)0);
		        int start = 0, len = excuses[i].excuse.length();
    	        while(start < len) {
    	            if(Character.isLetter(excuses[i].excuse.charAt(start))) {
		                int end = start + 1;
    	                while(end < excuses[i].excuse.length() && Character.isLetter(excuses[i].excuse.charAt(end)))
    	                    ++end;
		                String token = excuses[i].excuse.substring(start, end);
    	                if(binarySearch(keywords, token))
    	                    ++excuses[i].count;
		                start = end;
    	            }
    	            ++start;
		        }
    	        max = (short)Math.max(max, excuses[i].count);
    	    }
		    for(Excuse e : excuses) {
    	        if(e.count == max)
    	            output.append(e.excuse).append('\n');
		    }
    	    output.append('\n');
        }
        System.out.print(output);
	}
	
	static boolean binarySearch(ArrayList<String> arrayList, String key) {
        int left = 0, right = arrayList.size() - 1;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            int cmp = arrayList.get(mid).compareToIgnoreCase(key);
            if(cmp == 0)
                return true;
            if(cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
}

class Excuse {
    String excuse;
    short count;
    Excuse(String excuse, short count) {
        this.excuse = excuse;
        this.count = count;
    }
}
