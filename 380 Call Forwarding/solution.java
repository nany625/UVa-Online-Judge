import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    st.nextToken();
	    int N = (int)st.nval;
        StringBuilder output = new StringBuilder("CALL FORWARDING OUTPUT\n");
        for(int i = 1; i <= N; ++i) {
			output.append("SYSTEM " + i + "\n");
			ArrayList<Request> requests = new ArrayList<>();
			short source, time, duration, target;
			while(st.nextToken() == StreamTokenizer.TT_NUMBER && (source = (short)st.nval) != 0) {
			    st.nextToken();
			    time = (short)st.nval;
    		    st.nextToken();
    		    duration = (short)st.nval;
    		    st.nextToken();
    		    target = (short)st.nval;
    		    requests.add(new Request(source, time, duration, target));
    		}
    		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (time = (short)st.nval) != 9000) {
    			ArrayList<Short> calls = new ArrayList<>();
    			st.nextToken();
    			calls.add((short)st.nval);
    			boolean deadEnd = false;
    			int j = 0;
    			while(j < requests.size() && !deadEnd) {
    				if(calls.get(calls.size() - 1) == requests.get(j).source) {
    					if(time >= requests.get(j).time && time <= requests.get(j).time + requests.get(j).duration) {
    						if(calls.contains(requests.get(j).target))
    							deadEnd = true;
    						else {
    							calls.add(requests.get(j).target);
    							j = 0;
    						}
    					} else
    						++j;
					} else
    					++j;
    			}
				output.append(String.format("AT %04d CALL TO %04d RINGS %04d\n", time, calls.get(0), deadEnd ? 9999 : calls.get(calls.size() - 1)));
    		}
    	}
	    System.out.print(output + "END OF OUTPUT\n");
	}
}

class Request {
	short source, time, duration, target;
	Request(short source, short time, short duration, short target) {
		this.source = source;
		this.time = time;
		this.duration = duration;
		this.target = target;
	}
}
