import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int t = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            if(n == 0)
                break;
            output.append("Sums of ").append(t).append(":\n");
            int[] nums = new int[n], subset = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                nums[i] = (int)st.nval;
            }
            Set<String> subsetString = new HashSet<>();
            ArrayList<String> stringSet = new ArrayList<>();
            findSubsets(nums, t, 0, 0, subset, 0, subsetString, stringSet);
            if(stringSet.isEmpty())
                output.append("NONE\n");
            else {
                for(String s : stringSet)
                    output.append(s).append('\n');
            }
        }
        System.out.print(output);
    }
    
    static void findSubsets(int[] nums, int target, int index, int currentSum, int[] subset, int subsetSize, Set<String> subsetString, ArrayList<String> stringSet) {
        if(currentSum == target) {
            StringBuilder temp = new StringBuilder();
            for(int i = 0; i < subsetSize - 1; ++i)
                temp.append(subset[i]).append('+');
            temp.append(subset[subsetSize - 1]);
            String s = temp.toString();
            if(!subsetString.contains(s)) {
                subsetString.add(s);
                stringSet.add(s);
            }
            return;
        }
        if(currentSum > target || index == nums.length)
            return;
        for(int i = index; i < nums.length; ++i) {
            subset[subsetSize] = nums[i];
            findSubsets(nums, target, i + 1, currentSum + nums[i], subset, subsetSize + 1, subsetString, stringSet);
        }
    }
}
