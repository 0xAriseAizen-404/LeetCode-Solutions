class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt_targets = 0;
        int small_targets = 0;
        for (int& num: nums) {
            if (num == target) cnt_targets += 1;
            if (num < target) small_targets += 1;
        }
        vector<int> indices(cnt_targets);
        iota(indices.begin(), indices.end(), small_targets);
        return indices;
    }
};
// TC: O(N)
// SC: O(1)


// class Solution {
//     int first(vector<int>&nums, int target){
//         int low = 0 ; 
//         int high = nums.size()-1;
//         int ans = -1;
//         while(low <=high){
//             int mid = low + (high-low)/2;
//             if(nums[mid]== target){
//                  ans = mid;
//                  high = mid -1;
//             }else if(nums[mid]>target){
//                 high = mid -1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     };
//     int last(vector<int>&nums, int target){
//         int low = 0 ; 
//         int high = nums.size()-1;
//         int ans = -1;
//         while(low <=high){
//             int mid = low + (high-low)/2;
//             if(nums[mid]== target){
//                  ans = mid;
//                  low = mid + 1;
//             }else if(nums[mid]>target){
//                 high = mid -1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return ans;
//     };
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         vector<int>arr = nums;
//         sort(arr.begin(), arr.end());
//         int f = first(arr, target);
//         int l = last(arr, target);
//         vector<int> res;
//         if (f == -1) return res;  
//         for(int i = f; i<=l;i++){
//             res.push_back(i);
//         }
//         return res;
//     }
// };
// TC: O(nlogn)+O(logn)+O(logn)+O(k) = O(NlogN)
// SC: O(N)