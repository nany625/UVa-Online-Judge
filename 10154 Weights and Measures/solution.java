// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Turtle> turtles = new ArrayList<>();
        StreamTokenizer st = new StreamTokenizer(System.in);
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int w = (int)st.nval;
            st.nextToken();
            turtles.add(new Turtle(w, (int)st.nval));
        }
        turtles.sort(new Comparator<Turtle>() {
            @Override
            public int compare(Turtle t1, Turtle t2) {
                return Integer.compare(t1.strength, t2.strength);
            }
        });
        ArrayList<Integer> stacked = new ArrayList<>();
        int totalWeight = 0, height = 0;
        for(Turtle t : turtles) {
            if(totalWeight + t.weight <= t.strength) {
                stacked.add(t.weight);
                totalWeight += t.weight;
                ++height;
            } else if(height > 0) {
                int maxIndex = 0;
                for(int i = 1; i < height; ++i) {
                    if(stacked.get(i) > stacked.get(maxIndex))
                        maxIndex = i;
                }
                if(stacked.get(maxIndex) > t.weight) {
                    totalWeight += t.weight - stacked.get(maxIndex);
                    stacked.set(maxIndex, t.weight);
                }
            }
        }
	    System.out.println(height);
	}
}

class Turtle {
    int weight, strength;
    Turtle(int weight, int strength) {
        this.weight = weight;
        this.strength = strength;
    }
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<Turtle> turtles = new ArrayList<>();
        StreamTokenizer st = new StreamTokenizer(System.in);
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int w = (int)st.nval;
            st.nextToken();
            turtles.add(new Turtle(w, (int)st.nval));
        }
        turtles.sort(new Comparator<Turtle>() {
            @Override
            public int compare(Turtle t1, Turtle t2) {
                return Integer.compare(t1.strength, t2.strength);
            }
        });
        int[] dp = new int[turtles.size() + 1];
        Arrays.fill(dp, 1, turtles.size(), 1000000000);
        int maxHeight = 0;
        for(Turtle t : turtles) {
            for(int i = maxHeight; i >= 0; --i) {
                if(dp[i] + t.weight <= t.strength) {
                    dp[i + 1] = Math.min(dp[i + 1], dp[i] + t.weight);
                    maxHeight = Math.max(maxHeight, i + 1);
                }
            }
        }
	    System.out.println(maxHeight);
	}
}

class Turtle {
    int weight, strength;
    Turtle(int weight, int strength) {
        this.weight = weight;
        this.strength = strength;
    }
}
