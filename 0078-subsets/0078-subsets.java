import java.util.*;

class Solution {
    public void helper(List<List<Integer>> res, List<Integer> item, int[] nums, int ind) {
        if (ind >= nums.length) {
            res.add(new ArrayList<>(item));
            return;
        }
        
        helper(res, item, nums, ind+1); // not taking
        
        item.add(nums[ind]); // take
        helper(res, item, nums, ind+1);
        item.remove(item.size() - 1); // backtrack
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        helper(res, new ArrayList<>(), nums, 0);
        return res;
    }
}



// import java.util.ArrayList;
// import java.util.Comparator;
// import java.util.List;

// class Solution {
//     public List<List<Integer>> subsets(int[] nums) {
//         List<List<Integer>> res = new ArrayList<>();
//         int n = nums.length;
//         int powerSetLen = (int) Math.pow(2, n);

//         for (int num = 0; num < powerSetLen; num++) {
//             List<Integer> list = new ArrayList<>();
//             for (int ind = 0; ind < n; ++ind) {
//                 if ((num & (1 << ind)) != 0)
//                     list.add(nums[ind]);
//             }
//             res.add(list);
//         }

//         // Sorting the subsets based on their sizes
//         res.sort(new Comparator<List<Integer>>() {
//             @Override
//             public int compare(List<Integer> a, List<Integer> b) {
//                 return Integer.compare(a.size(), b.size());
//             }
//         });

//         return res;
//     }
// }
