import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            String decode;
            while((decode = br.readLine()) != null && !decode.isEmpty()) {
                for(int i = 0; i < decode.length(); ++i) {
                    switch(decode.charAt(i)) {
                        case '0':
                            output.append('O');
                            break;
                        case '1':
                            output.append('I');
                            break;
                        case '2':
                            output.append('Z');
                            break;
                        case '3':
                            output.append('E');
                            break;
                        case '4':
                            output.append('A');
                            break;
                        case '5':
                            output.append('S');
                            break;
                        case '6':
                            output.append('G');
                            break;
                        case '7':
                            output.append('T');
                            break;
                        case '8':
                            output.append('B');
                            break;
                        case '9':
                            output.append('P');
                            break;
                        default:
                            output.append(decode.charAt(i));
                    }
                }
                output.append('\n');
            }
            if(T > 0)
                output.append('\n');
        }
        System.out.print(output);
    }
}
