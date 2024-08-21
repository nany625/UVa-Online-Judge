import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        int[] teamNum = new int[1000000];
        StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, t;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (t = (int)st.nval) != 0) {
    	    output.append("Scenario #").append(++cases).append('\n');
    		for(int i = 0; i < t; ++i) {
    			st.nextToken();
    			int elementCount = (int)st.nval;
    			while(elementCount-- > 0) {
    			    st.nextToken();
    				teamNum[(int)st.nval] = i;
    			}
    		}
            ArrayList<Integer> queue = new ArrayList<>();
            int next = 0;
		    String command;
    	    while(st.nextToken() == StreamTokenizer.TT_WORD && (command = st.sval).charAt(0) != 'S') {
    	        if(command.charAt(0) == 'E') {
    			    st.nextToken();
    			    queue.add((int)st.nval);
    	        } else if(command.charAt(0) == 'D') {
    			    int dequeue = queue.get(next);
    			    output.append(dequeue).append('\n');
    			    queue.remove(next);
    			    int currTeam = teamNum[dequeue];
    			    while(next < queue.size() && teamNum[queue.get(next)] != currTeam)
    			        ++next;
    			    if(next == queue.size())
    			        next = 0;
    			}
    	    }
    	    output.append('\n');
        }
	    System.out.print(output);
	}
}
