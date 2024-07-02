import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            short max = 1;
	        LinkedList<Short> stack = new LinkedList<>();
    		LinkedList<Short> queue = new LinkedList<>();
    		LinkedList<Short> priorityQueue = new LinkedList<>();
    		boolean isStack = true, isQueue = true, isPriorityQueue = true;
    		while(n-- > 0) {
    		    st.nextToken();
    			int command = (int)st.nval;
    			st.nextToken();
    			short x = (short)st.nval;
    			if(command == 1){
    				stack.add(x);
    				queue.add(x);
    				priorityQueue.add(x);
    				max = (short)Math.max(max, x);
    			} else if(command == 2) {
					if(!priorityQueue.contains(x))
    					isStack = isQueue = isPriorityQueue = false;
    				else {
    					if(isStack && x != stack.removeLast())
    						isStack = false;
						if(isQueue && x != queue.removeFirst())
    						isQueue = false;
    					priorityQueue.remove(Short.valueOf(x));
    					if(x == max) {
							max = 1;
    						for(Short s : priorityQueue)
    							max = (short)Math.max(max, s);
    					} else
							isPriorityQueue = false;	
    				}
    			}
    		}
    		if(!isStack && !isQueue && !isPriorityQueue)
    			output.append("impossible\n");
			else if((isStack && isQueue) || (isQueue && isPriorityQueue) || (isStack && isPriorityQueue))
    			output.append("not sure\n");
    		else if(isStack)
				output.append("stack\n");
    		else if(isQueue)
    			output.append("queue\n");
			else if(isPriorityQueue)
    			output.append("priority queue\n");
	    }
	    System.out.print(output);
	}
}
