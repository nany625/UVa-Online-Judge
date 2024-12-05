import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int n = (int)st.nval;
    	    Product[] products = new Product[n];
    	    for(int i = 0; i < n; ++i) {
    	        products[i] = new Product();
    	        st.nextToken();
    	        products[i].p = (int)st.nval;
    	        st.nextToken();
    	        products[i].d = (int)st.nval;
    	    }
    	    Arrays.sort(products, new Comparator<Product>() {
    	        @Override
    	        public int compare(Product p1, Product p2) {
    	            return Integer.compare(p1.d, p2.d);
    	        }
    	    });
    	    ArrayList<Integer> priorityQueue = new ArrayList<>();
    	    for(Product p : products) {
    	        if(p.d > priorityQueue.size())
    	            priorityQueue.add(p.p);
    	        else {
    	            int minIndex = 0;
    	            for(int j = 1; j < priorityQueue.size(); ++j) {
    	                if(priorityQueue.get(j) < priorityQueue.get(minIndex))
    	                    minIndex = j;
    	            }
    	            priorityQueue.set(minIndex, Math.max(priorityQueue.get(minIndex), p.p));
    	        }
    	    }
    	    int profit = 0;
    	    for(Integer i : priorityQueue)
    	        profit += i;
    	    output.append(profit).append('\n');
    	}
        System.out.print(output);
	}
}

class Product {
    int p, d;
}
