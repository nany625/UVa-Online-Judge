// #解法一
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        ArrayList<Conquest> conquests = new ArrayList<>();
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            st.nextToken();
            String country = st.sval;
            int pos = binarySearch(conquests, country);
            if(pos < conquests.size() && conquests.get(pos).country.equals(country))
                ++conquests.get(pos).count;
            else 
                conquests.add(pos, new Conquest(country, (char)1));
            br.readLine();
        }
        for(Conquest c : conquests)
            output.append(c.country + " " + (int)c.count + "\n");
        System.out.print(output);
    }
    
    static int binarySearch(ArrayList<Conquest> arrayList, String key) {
        int left = 0, right = arrayList.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = arrayList.get(mid).country.compareTo(key);
            if(cmp == 0)
                return mid;
            if(cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

class Conquest {
    String country;
    char count;
    Conquest(String country, char count) {
        this.country = country;
        this.count = count;
    }
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        HashMap<String, Character> conquests = new HashMap<>();
        ArrayList<String> conquestsKeys = new ArrayList<>();
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            st.nextToken();
            String country = st.sval;
            if(conquests.containsKey(country))
            	conquests.replace(country, (char)(conquests.get(country) + 1));
            else {
            	conquests.put(country, (char)1);
            	conquestsKeys.add(country);
            }
            br.readLine();
        }
        Collections.sort(conquestsKeys);
        for(String s : conquestsKeys)
            output.append(s + " " + (int)conquests.get(s) + "\n");
        System.out.print(output);
    }	
}

// #解法三
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int n = Integer.parseInt(br.readLine());
        TreeMap<String, Character> conquests = new TreeMap<>();
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
            st.nextToken();
            String country = st.sval;
            if(conquests.containsKey(country))
            	conquests.replace(country, (char)(conquests.get(country) + 1));
            else
            	conquests.put(country, (char)1);
            br.readLine();
        }
        for(String s : conquests.keySet())
            output.append(s + " " + (int)conquests.get(s) + "\n");
        System.out.print(output);
    }	
}
