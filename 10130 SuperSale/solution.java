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
            int N = (int)st.nval;
            Object[] objects = new Object[N];
            for(int i = 0; i < N; ++i) {
                objects[i] = new Object();
                st.nextToken();
                objects[i].P = (short)st.nval;
                st.nextToken();
                objects[i].W = (short)st.nval;
            }
            st.nextToken();
            int G = (int)st.nval;
            short[] MW = new short[G];
            short capacity = 0;
            for(int i = 0; i < G; ++i) {
                st.nextToken();
                capacity = (short)Math.max(capacity, MW[i] = (short)st.nval);
            }
            int[] dp = new int[capacity + 1];
            for(Object o : objects) {
                for(int j = capacity; j >= o.W; --j)
                    dp[j] = Math.max(dp[j], dp[j - o.W] + o.P);
            }
            int maxValue = 0;
            for(Short s : MW)
                maxValue += dp[s];
            output.append(maxValue).append('\n');
    	}
        System.out.print(output);
	}
}

class Object {
    short P, W;
}
