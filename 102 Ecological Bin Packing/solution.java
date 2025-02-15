import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		int[] bottles = new int[9], total = new int[6];
        String[] color = {"BGC", "GCB", "CBG", "CGB", "GBC", "BCG"};
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    bottles[0] = (int)st.nval;
		    for(int i = 1; i < 9; ++i) {
		        st.nextToken();
		        bottles[i] = (int)st.nval;
		    }
		    total[0] = bottles[0] + bottles[4] + bottles[8];
            total[1] = bottles[1] + bottles[5] + bottles[6];
            total[2] = bottles[2] + bottles[3] + bottles[7];
            total[3] = bottles[2] + bottles[4] + bottles[6];
            total[4] = bottles[1] + bottles[3] + bottles[8];
            total[5] = bottles[0] + bottles[5] + bottles[7];
            int maxTotal = 0, maxIndex = 0;
            for(int i = 0; i < 6; ++i) {
                if(total[i] > maxTotal)
                    maxTotal = total[maxIndex = i];
                else if(total[i] == maxTotal && color[i].compareTo(color[maxIndex]) < 0)
                    maxIndex = i;
            }
            output.append(color[maxIndex]).append(' ').append(total[0] + total[1] + total[2] - maxTotal).append('\n');
		}
		System.out.print(output);
	}
}
