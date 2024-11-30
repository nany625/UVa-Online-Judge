import java.io.*;

public class Main {
    static int[] requirement = {3, 1, 1, 1, 2};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            String ingredients = st.sval;
            int[] count = new int[6];
            for(int i = 0; i < ingredients.length(); ++i) {
                switch(ingredients.charAt(i)) {
                    case 'A':
                        ++count[0];
                        break;
                    case 'G':
                        ++count[1];
                        break;
                    case 'I':
                        ++count[2];
                        break;
                    case 'M':
                        ++count[3];
                        break;
                    case 'R':
                        ++count[4];
                        break;
                    case 'T':
                        ++count[5];
                }
            }
            int min = count[5];
            for(int i = 0; i < 5; ++i)
                min = Math.min(min, count[i] / requirement[i]);
            output.append(min).append('\n');
        }
        System.out.print(output);
    }
}
