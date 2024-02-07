import java.util.*;

class Solution {
    public String frequencySort(String s) {
        HashMap<Character, Integer> hMap = new HashMap<>();
        for (char x : s.toCharArray()) {
            hMap.put(x, hMap.getOrDefault(x, 0) + 1);
        }
        
        List<Map.Entry<Character, Integer>> list = new ArrayList<>(hMap.entrySet());
        list.sort((a, b) -> b.getValue().compareTo(a.getValue()));

        StringBuilder sb = new StringBuilder();
        for (Map.Entry<Character, Integer> entry : list) {
            for (int i = 0; i < entry.getValue(); i++) {
                sb.append(entry.getKey());
            }
        }
        return sb.toString();
    }
}
