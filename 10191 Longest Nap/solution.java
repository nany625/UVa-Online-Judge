import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int day = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int s = (int)st.nval;
            Appointment[] appointments = new Appointment[s + 2];
            appointments[0] = new Appointment(0, 600);
            appointments[s + 1] = new Appointment(1080, 0);
            int hh, mm;
            for(int i = 1; i < s + 1; ++i) {
    	        String[] tokens = br.readLine().split("\\s+");
    	        String[] time = tokens[0].split(":");
    	        int time1 = 60 * Integer.parseInt(time[0]) + Integer.parseInt(time[1]);
    	        time = tokens[1].split(":");
    	        int time2 = 60 * Integer.parseInt(time[0]) + Integer.parseInt(time[1]);
    	        appointments[i] = new Appointment(time1, time2);
    	    }
    	    Arrays.sort(appointments, new Comparator<Appointment>() {
    	        @Override
    	        public int compare(Appointment a1, Appointment a2) {
    	            return Integer.compare(a1.time1, a2.time1);
    	        }
    	    });
    	    int longest = appointments[1].time1 - 600, start = 600;
    	    for(int i = 2; i < s + 2; ++i) {
    	        if(longest < appointments[i].time1 - appointments[i - 1].time2) {
    	            longest = appointments[i].time1 - appointments[i - 1].time2;
    	            start = appointments[i - 1].time2;
    	        }
    	    }
    	    output.append(String.format("Day #%d: the longest nap starts at %02d:%02d and will last for ", ++day, start / 60, start % 60));
    	    if(longest >= 60)
    	        output.append(String.format("%d hours and %d minutes.\n", longest / 60, longest % 60));
    	    else
    	        output.append(String.format("%d minutes.\n", longest));
        }
        System.out.print(output);
	}
}

class Appointment {
    int time1, time2;
    Appointment(int time1, int time2) {
        this.time1 = time1;
        this.time2 = time2;
    }
}
