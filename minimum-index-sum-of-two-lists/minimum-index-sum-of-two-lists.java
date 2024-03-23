import java.util.*;

class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> umap = new HashMap<>();
        Map<String, Integer> myMap = new HashMap<>();
        
        for (int i = 0; i < list1.length; ++i) {
            umap.put(list1[i], i);
        }
        
        int minIndSum = Integer.MAX_VALUE;
        
        for (int i = 0; i < list2.length; ++i) {
            if (umap.containsKey(list2[i])) {
                minIndSum = Math.min(minIndSum, i + umap.get(list2[i]));
                myMap.put(list2[i], myMap.getOrDefault(list2[i], 0) + umap.get(list2[i]) + i);
            }
        }
        
        List<String> ansList = new ArrayList<>();
        
        for (Map.Entry<String, Integer> entry : myMap.entrySet()) {
            if (entry.getValue() == minIndSum) {
                ansList.add(entry.getKey());
            }
        }
        
        return ansList.toArray(new String[0]);
    }
}
