import java.io.*;
import java.util.*;

public class Main {
    static String[] firstGrid = new String[6], secondGrid = new String[6];
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            int K = Integer.parseInt(br.readLine());
            for(int i = 0; i < 6; ++i)
				firstGrid[i] = br.readLine();
    		for(int i = 0; i < 6; ++i)
    		    secondGrid[i] = br.readLine();
			ArrayList<Character> p1 = new ArrayList<>();
    		ArrayList<Character> p2 = new ArrayList<>();
    		ArrayList<Character> p3 = new ArrayList<>();
			ArrayList<Character> p4 = new ArrayList<>();
    		ArrayList<Character> p5 = new ArrayList<>();
    		filter(p1, 0);
            filter(p2, 1);
            filter(p3, 2);
            filter(p4, 3);
            filter(p5, 4);
			if(p1.size() * p2.size() * p3.size() * p4.size() * p5.size() < K)
    			output.append("NO\n");
    		else {
				Collections.sort(p1);
    			Collections.sort(p2);
    			Collections.sort(p3);
				Collections.sort(p4);
    			Collections.sort(p5);
    			output.append(p1.get(--K / p2.size() / p3.size() / p4.size() / p5.size()));
				K %= p2.size() * p3.size() * p4.size() * p5.size();
    			output.append(p2.get(K / p3.size() / p4.size() / p5.size()));
    			K %= p3.size() * p4.size() * p5.size();
				output.append(p3.get(K / p4.size() / p5.size()));
    			K %= p4.size() * p5.size();
    			output.append(p4.get(K / p5.size())).append(p5.get(K % p5.size())).append('\n');
    		}
        }
	    System.out.print(output);
	}
	
	static void filter(ArrayList<Character> arrayList, int p) {
	    for(int i = 0; i < 6; ++i) {
			for(int j = 0; j < 6; ++j) {
				if(firstGrid[i].charAt(p) == secondGrid[j].charAt(p)) {
					if(!arrayList.contains(firstGrid[i].charAt(p)))
						arrayList.add(firstGrid[i].charAt(p));
					break;
				}
			}
		}
	}
}
