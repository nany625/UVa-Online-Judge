import java.io.*;
import java.util.*;

public class Main {
    static ArrayList<Coordinate> lostCoordinates = new ArrayList<>();
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int boundX = (int)st.nval;
            st.nextToken();
            int boundY = (int)st.nval;
    		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    		    int x = (int)st.nval;
                st.nextToken();
                int y = (int)st.nval;
                st.nextToken();
                char orientation = st.sval.charAt(0);
                boolean lost = false;
                String instructions = br.readLine();
                int len = instructions.length();
    		    for(int i = 0; i < instructions.length() && !lost; ++i) {
    		        if(orientation == 'N') {
    		            if(instructions.charAt(i) == 'L')
    		                orientation = 'W';
    		            else if(instructions.charAt(i) == 'R')
    		                orientation = 'E';
    		            else if(instructions.charAt(i) == 'F') {
    		                if(y < boundY)
    		                    ++y;
    		                else if(!contain(x, y)) {
    		                    lostCoordinates.add(new Coordinate(x, y));
    		                    lost = true;
    		                }
    		            }
    		        } else if(orientation == 'E') {
    		            if(instructions.charAt(i) == 'L')
    		                orientation = 'N';
    		            else if(instructions.charAt(i) == 'R')
    		                orientation = 'S';
    		            else if(instructions.charAt(i) == 'F') {
    		                if(x < boundX)
    		                    ++x;
    		                else if(!contain(x, y)) {
    		                    lostCoordinates.add(new Coordinate(x, y));
    		                    lost = true;
    		                }
    		            }
    		        } else if(orientation == 'S') {
    		            if(instructions.charAt(i) == 'L')
    		                orientation = 'E';
    		            else if(instructions.charAt(i) == 'R')
    		                orientation = 'W';
    		            else if(instructions.charAt(i) == 'F') {
    		                if(y > 0)
    		                    --y;
    		                else if(!contain(x, y)) {
    		                    lostCoordinates.add(new Coordinate(x, y));
    		                    lost = true;
    		                }
    		            }
    		        } else {
    		            if(instructions.charAt(i) == 'L')
    		                orientation = 'S';
    		            else if(instructions.charAt(i) == 'R')
    		                orientation = 'N';
    		            else if(instructions.charAt(i) == 'F') {
    		                if(x > 0)
    		                    --x;
    		                else if(!contain(x, y)) {
    		                    lostCoordinates.add(new Coordinate(x, y));
    		                    lost = true;
    		                }
    		            }
    		        }
    		    }
    		    System.out.println(x + " " + y + " " + orientation + (lost ? " LOST" : ""));
    		}
        } catch(IOException e) {};
	}
	
	static boolean contain(int x, int y) {
	    for(int i = 0; i < lostCoordinates.size(); ++i) {
	        if(lostCoordinates.get(i).x == x && lostCoordinates.get(i).y == y)
	            return true;
	    }
	    return false;
	}
}

class Coordinate {
    int x, y;
    Coordinate(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
