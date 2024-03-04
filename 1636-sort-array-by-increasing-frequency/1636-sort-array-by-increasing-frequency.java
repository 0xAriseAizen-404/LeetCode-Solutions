import java.util.*;

class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> hMap = new HashMap<>();
        
        for (int x : nums) {
            hMap.put(x, hMap.getOrDefault(x, 0) + 1);
        }
        
        List<Integer> ans = new ArrayList<>(hMap.keySet());
        ans.sort((x, y) -> {
            int freqComparison = Integer.compare(hMap.get(x), hMap.get(y));
            return freqComparison != 0 ? freqComparison : Integer.compare(y, x);
        });

        int ind = 0;
        int[] res = new int[nums.length];
        
        for (int i = 0; i < ans.size(); ++i) {
            for (int j = 0; j < hMap.get(ans.get(i)); ++j) {
                res[ind++] = ans.get(i);
            }
        }
        
        return res;
    }
}
