class Solution {
    public int ret;
    public void mergeSort(int[] nums, int left, int right) {
        if (right <= left) {
            return;
        }
        int middle = left + (right - left)/2;
        mergeSort(nums, left, middle);
        mergeSort(nums,middle+1, right);

        //count elements
        int count = 0;
        for (int l = left, r = middle+1; l <= middle;) {
            if (r > right || (long)nums[l] <= 2*(long)nums[r]) {
                l++;
                ret += count;
            } else {
                r++;
                count++;
            }
        }
        
        //merge sort
        int[] temp = new int[right - left + 1];
        for (int l = left, r = middle+1, k = 0; l <= middle || r <= right;) {
            if (l <= middle && ((r > right) || nums[l] < nums[r])) {
                temp[k++] = nums[l++];
            } else {
                temp[k++] = nums[r++];
            }
        }
        for (int i = 0; i < temp.length; i++) {
            nums[left + i] = temp[i];
        }
    }

    public int reversePairs(int[] nums) {
        ret = 0;
        mergeSort(nums, 0, nums.length-1);
        return ret ;
    }
}

// class Solution {
//     int count;
//     public int reversePairs(int[] nums) {
//         count = 0;
//         merger(nums,0,nums.length-1);

//         return count;
//     }
//     private ArrayList<Integer> merge(ArrayList<Integer> left,ArrayList<Integer> right){
//         ArrayList<Integer> ans = new ArrayList<>();
//         int i = 0;
//         int j = 0;
//         while(i < left.size() && j < right.size()){
//             if (left.get(i) >right.get(j)){
//                 ans.add(right.get(j));
//                 j++;
//             }
//             else {
//                 ans.add(left.get(i));
//                 i++;
//             }
//            /* else if(left.get(i) == right.get(j)){
//                 ans.add(left.get(i));
//                 ans.add(right.get(j));
//                 i++;
//                 j++;
//             }*/
//         }
//         if ( i < left.size()){
//             while (i <left.size())
//              ans.add(left.get(i++));
//         }
//         if(j < right.size()){
//             while (j < right.size())
//              ans.add(right.get(j++));
//         }
//         return ans;
//     }
//     private void helper(ArrayList<Integer> left,ArrayList<Integer> right){
//         int i = 0;
//         int j = 0;
//         while (i < left.size() && j < right.size()){
//             if(left.get(i) > 2*(long)right.get(j)){
//                 count += left.size() - i;
//                 j++;
//             }
//             else
//             i++;
//         }
        
//     }
//     private ArrayList<Integer> merger(int[] nums,int start,int end){
//         if(start == end){
//             ArrayList<Integer> temp = new ArrayList<>();
//             temp.add(nums[start]);
//             return temp;
//         }
//         int mid = (start + end)/2;
        
//         ArrayList<Integer> left = merger(nums,start,mid);
//         ArrayList<Integer> right = merger(nums,mid+1,end);
//         helper(left,right);
        
//         return merge(left,right);

//     }
// }