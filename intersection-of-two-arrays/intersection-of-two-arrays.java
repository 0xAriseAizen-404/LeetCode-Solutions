import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        List<Integer> ansList = new ArrayList<>();
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        
        int i = 0;
        int j = 0;
        
        while (i < nums1.length && j < nums2.length) {
            // Skip duplicate entries in nums1
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            
            if (nums1[i] == nums2[j]) {
                ansList.add(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        // Convert List to array
        int[] ansArray = new int[ansList.size()];
        for (int k = 0; k < ansList.size(); k++) {
            ansArray[k] = ansList.get(k);
        }
        
        return ansArray;
    }
}
