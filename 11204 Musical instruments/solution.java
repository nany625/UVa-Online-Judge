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
            int N = (int)st.nval;
            st.nextToken();
            int M = (int)st.nval;
            int[] priority = new int[N];
            while(M-- > 0) {
                for(int i = 0; i < N; ++i) {
                    st.nextToken();
                    if((int)st.nval == 1)
                        ++priority[i];
                }
            }
            int distribution = 1;
            for(Integer i : priority) {
                if(i > 0)
                    distribution *= i;
            }
            output.append(distribution).append('\n');
        }
        System.out.print(output);
    }
}
