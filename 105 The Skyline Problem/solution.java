// #解法一
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		short[] skyline = new short[10000];
		int limit = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int L = (int)st.nval;
		    st.nextToken();
		    int H = (int)st.nval;
		    st.nextToken();
		    int R = (int)st.nval;
		    for(int i = L; i < R; ++i)
		        skyline[i] = (short)Math.max(skyline[i], H);
		    limit = (short)Math.max(limit, R);
		}
		boolean firstBuilding = true;
		for(int i = 1; i <= limit; ++i) {
    	    if(skyline[i] != skyline[i - 1]) {
    	        if(!firstBuilding)
    	            output.append(' ');
    	        output.append(i).append(' ').append(skyline[i]);
    	        firstBuilding = false;
    	    }
    	}
		System.out.println(output);
	}
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		short[] skyline = new short[10000];
		ArrayList<Integer> check = new ArrayList<>();
		boolean[] isBuilding = new boolean[10000];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int L = (int)st.nval;
		    st.nextToken();
		    int H = (int)st.nval;
		    st.nextToken();
		    int R = (int)st.nval;
		    if(skyline[L] < H && !isBuilding[L]) {
		        check.add(L);
		        isBuilding[L] = true;
		    }
		    if(skyline[R] < H && !isBuilding[R]) {
		        check.add(R);
		        isBuilding[R] = true;
		    }
		    for(int i = L; i < R; ++i)
		        skyline[i] = (short)Math.max(skyline[i], H);
		}
		Collections.sort(check);
		boolean firstBuilding = true;
		int size = check.size();
		for(int i = 0; i < size; ++i) {
    	    if(skyline[check.get(i)] != skyline[check.get(i) - 1]) {
    	        if(!firstBuilding)
    	            output.append(' ');
    	        output.append(check.get(i)).append(' ').append(skyline[check.get(i)]);
    	        firstBuilding = false;
    	    }
    	}
		System.out.println(output);
	}
}
