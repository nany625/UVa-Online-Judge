import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int capacity = (int)st.nval;
            st.nextToken();
            int temperature = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            Jar[] jars = new Jar[n];
            for(int i = 0; i < n; ++i) {
                jars[i] = new Jar();
                st.nextToken();
                jars[i].volume = (int)st.nval;
                st.nextToken();
                jars[i].temperature = (int)st.nval * jars[i].volume;
            }
            int start = -1, end = -1;
            double diff = 5.1;
            for(int i = 0; i < n; ++i) {
                int totalVolume = 0;
                double totalTemperature = 0;
                for(int j = i; j < n; ++j) {
                    totalVolume += jars[j].volume;
                    if(totalVolume > capacity)
                        break;
                    totalTemperature += jars[j].temperature;
                    if(totalVolume << 1 >= capacity) {
                        double mixTemperature = totalTemperature / totalVolume;
                        if(diff > Math.abs(mixTemperature - temperature)) {
                            start = i;
                            end = j;
                            diff = Math.abs(mixTemperature - temperature);
                        }
                    }
                }
            }
            if(diff > 5)
                output.append("Not possible\n");
            else
                output.append(start).append(' ').append(end).append('\n');
        }
	    System.out.print(output);
	}
}

class Jar {
    int volume, temperature;
}
