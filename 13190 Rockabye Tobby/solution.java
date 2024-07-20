import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    st.nextToken();
		    int k = (int)st.nval;
		    Medicine[] medicines = new Medicine[n];
		    for(int i = 0; i < n; ++i) {
		        String[] tokens = br.readLine().split("\\s+");
		        medicines[i] = new Medicine(tokens[0], Integer.parseInt(tokens[1]));
		    }
		    while(k > 0) {
		        int min = medicines[0].next;
		        for(int i = 1; i < n; ++i)
		            min = Math.min(min, medicines[i].next);
		        for(int i = 0; i < n && k > 0; ++i) {
		            if(min == medicines[i].next) {
		                output.append(min + " " + medicines[i].name + "\n");
		                medicines[i].next += medicines[i].frequency;
		                --k;
		            }
		        }
		    }
		}
		System.out.print(output);
	}
}

class Medicine {
    String name;
    int frequency, next;
    Medicine(String name, int frequency) {
        this.name = name;
        this.frequency = this.next = frequency;
    }
}
