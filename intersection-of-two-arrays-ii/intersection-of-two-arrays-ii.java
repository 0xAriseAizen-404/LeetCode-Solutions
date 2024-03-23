public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        // create hash maps to count the frequency of each element
        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        for (int num : nums1) {
            map1.put(num, map1.getOrDefault(num, 0) + 1);
        }
        for (int num : nums2) {
            map2.put(num, map2.getOrDefault(num, 0) + 1);
        }
        
        // iterate over the elements in the hash maps and add the common elements to a new array
        List<Integer> list = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map1.entrySet()) {
            int num = entry.getKey();
            if (map2.containsKey(num)) {
                int count = Math.min(entry.getValue(), map2.get(num));
                for (int i = 0; i < count; i++) {
                    list.add(num);
                }
            }
        }
        
        // convert the list to an array and return it
        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;
    }
}