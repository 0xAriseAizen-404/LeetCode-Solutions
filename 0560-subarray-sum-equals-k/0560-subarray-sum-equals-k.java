// class Solution {
//     public int subarraySum(int[] nums, int k) {
//         int sum = nums[0], left = 0, right = 1;
//         int cnt = 0;
//         while(left<nums.length){
//             if(sum == k){
//                 cnt++;
//                 sum -= nums[left++];
//             }
//             else if(sum < k ){
//                 if(right!=nums.length) sum += nums[right++];
//                 else sum -= nums[left++];
//             }
//             else sum -= nums[left++];
//         }
//         return cnt;
//     }
// }

class Solution {
    public int subarraySum(int[] nums, int k) {
       int count=0;
        Map<Integer, Integer> map = new HashMap<>();
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(sum==k)  count++;
            if(map.containsKey(sum-k)){
                count+= map.get(sum-k);
            }
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
         return count; 
    }
}