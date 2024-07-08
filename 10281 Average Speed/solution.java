import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int prevHour = 0, prevMinute = 0, prevSecond = 0, prevSpeed = 0;
        float dist = 0;
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.split("\\s+|:");
            int currHour = Integer.parseInt(tokens[0]);
            int currMinute = Integer.parseInt(tokens[1]);
            int currSecond = Integer.parseInt(tokens[2]);
            dist += (3600 * (currHour - prevHour) + 60 * (currMinute - prevMinute) + (currSecond - prevSecond)) / 3600.0 * prevSpeed;
            if(tokens.length == 3)
                output.append(String.format("%02d:%02d:%02d %.2f km\n", currHour, currMinute, currSecond, dist));
            else if(tokens.length == 4)
                prevSpeed = Integer.parseInt(tokens[3]);
            prevHour = currHour;
            prevMinute = currMinute;
            prevSecond = currSecond;
        }
        System.out.print(output);
	}
}
