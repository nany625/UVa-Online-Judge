import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = 0;
        String S;
        StringBuilder output = new StringBuilder();
        while((S = br.readLine()) != null && !S.equals("#")) {
            output.append("Case ").append(++cases).append(": ");
            if(S.equals("HELLO"))
                output.append("ENGLISH\n");
            else if(S.equals("HOLA"))
                output.append("SPANISH\n");
            else if(S.equals("HALLO"))
                output.append("GERMAN\n");
            else if(S.equals("BONJOUR"))
                output.append("FRENCH\n");
            else if(S.equals("CIAO"))
                output.append("ITALIAN\n");
            else if(S.equals("ZDRAVSTVUJTE"))
                output.append("RUSSIAN\n");
            else
                output.append("UNKNOWN\n");
        }
        System.out.print(output);
    }
}
