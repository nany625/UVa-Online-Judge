import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    ArrayList<Event> events = new ArrayList<>();
		    while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		        short s = (short)st.nval;
		        st.nextToken();
		        short f = (short)st.nval;
		        if(s == 0 && f == 0)
		            break;
		        events.add(new Event(s, f));
		    }
		    events.sort(new Comparator<Event>() {
		        @Override
		        public int compare(Event e1, Event e2) {
		            return Short.compare(e1.f, e2.f);
		        }
		    });
		    int end = 0, count = 0;
		    for(Event e : events) {
		        if(e.s >= end) {
		            end = e.f;
		            ++count;
		        }
		    }
		    output.append(count).append('\n');
		}
        System.out.print(output);
	}
}

class Event {
    short s, f;
    Event(short s, short f) {
        this.s = s;
        this.f = f;
    }
}
