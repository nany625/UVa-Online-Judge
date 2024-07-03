import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
    	    String[] A = line.split("\\s+");
    	    String[] B = br.readLine().split("\\s+");
    	    ArrayList<String> setA = new ArrayList<>();
    		ArrayList<String> setB = new ArrayList<>();
    		ArrayList<String> union = new ArrayList<>();
    		for(String s : A) {
    			if(!setA.contains(s))
    				setA.add(s);
    			if(!union.contains(s))
    				union.add(s);
    		}
    		for(String s : B) {
    			if(!setB.contains(s))
    				setB.add(s);
    			if(!union.contains(s))
    				union.add(s);
    		}
    		if(union.size() == setA.size() && union.size() == setB.size())
    			output.append("A equals B\n");
    		else if(union.size() == setA.size() && union.size() != setB.size())
    			output.append("B is a proper subset of A\n");
    		else if(union.size() == setB.size() && union.size() != setA.size())
    			output.append("A is a proper subset of B\n");
    		else if(union.size() == setA.size() + setB.size())
    			output.append("A and B are disjoint\n");
    		else
    			output.append("I'm confused!\n");
    	}
        System.out.print(output);
	}
}
