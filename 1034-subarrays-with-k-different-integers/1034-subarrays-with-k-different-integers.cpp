class Solution {
private:
    int myHelper(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < nums.size()) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                if (--freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return myHelper(nums, k) - myHelper(nums, k - 1);
    }
};


// class Solution {
// private:
//     int myHelper(vector<int>& nums, int k) {
//         unordered_set<int> sset;
//         int left = 0;
//         int right = 0;
//         int count = 0;
//         while (right < nums.size()) {
//             sset.insert(nums[right]);
//             while (sset.size() > k) sset.erase(nums[left++]);
//             count += (right - left + 1);
//             right++;
//         }
//         return count;
//     }
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return myHelper(nums, k) - myHelper(nums, k - 1);
//     }
// };