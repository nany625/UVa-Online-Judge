// #解法一
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        HashMap<String, Short> conquests = new HashMap<>();
        ArrayList<String> conquestsKeys = new ArrayList<>();
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            st.nextToken();
            String country = st.sval;
            if(conquests.containsKey(country))
            	conquests.replace(country, (short)(conquests.get(country) + 1));
            else {
            	conquests.put(country, (short)1);
            	conquestsKeys.add(country);
            }
            br.readLine();
        }
        Collections.sort(conquestsKeys);
        for(String s : conquestsKeys)
            output.append(s).append(' ').append(conquests.get(s)).append('\n');
        System.out.print(output);
    }	
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int n = Integer.parseInt(br.readLine());
        TreeMap<String, Short> conquests = new TreeMap<>();
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            st.nextToken();
            String country = st.sval;
            conquests.put(country, (short)(conquests.getOrDefault(country, (short)0) + 1));
            br.readLine();
        }
        for(String s : conquests.keySet())
            output.append(s).append(' ').append(conquests.get(s)).append('\n');
        System.out.print(output);
    }	
}
