import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        String[] HaabMonth = {
            "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
            "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
        };
        String[] TzolkinName = {
            "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
            "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
        };
        HashMap<String, Integer> Haab = new HashMap<>();
        for(int i = 0; i < 19; ++i)
            Haab.put(HaabMonth[i], i);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder(n + "\n");
        while(n-- > 0) {
            st.nextToken();
            int day = (int)st.nval;
            st.nextToken();
            String month = st.sval;
            st.nextToken();
            int year = (int)st.nval;
            int totalDays = day + 20 * Haab.get(month) + 365 * year;
            output.append(totalDays % 13 + 1).append(' ').append(TzolkinName[totalDays % 20]).append(' ').append(totalDays / 260).append('\n');
        }
	    System.out.print(output);
	}
}
