import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            String line;
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
    				System.out.println("A equals B");
    			else if(union.size() == setA.size() && union.size() != setB.size())
    				System.out.println("B is a proper subset of A");
    			else if(union.size() == setB.size() && union.size() != setA.size())
    				System.out.println("A is a proper subset of B");
    			else if(union.size() == setA.size() + setB.size())
    				System.out.println("A and B are disjoint");
    			else
    				System.out.println("I'm confused!");
    		}
        } catch(IOException e) {};
	}
}
