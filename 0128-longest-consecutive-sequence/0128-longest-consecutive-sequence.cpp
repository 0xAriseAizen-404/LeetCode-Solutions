// class Solution {
// private: 
//     bool longestConsecutive(vector<int>& nums, int target){
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             if(nums[i] == target){
//                 return true;
//             }
//         }
//         return false;
//     }
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         int longestConsecutiveSequence = 0;
//         for(auto num : nums){
//             int currentNumber = num;
//             int currentConsecutiveSequence = 1;
//             while(longestConsecutive(nums, currentNumber+1)){
//                 currentNumber += 1;
//                 currentConsecutiveSequence += 1;
//             }
//             longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
//         }
//         return longestConsecutiveSequence;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                if(count>maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};