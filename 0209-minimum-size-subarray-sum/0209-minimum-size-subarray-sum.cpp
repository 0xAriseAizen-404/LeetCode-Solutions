class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int left = 0;
        int right = 0;
        int currSum = 0;
        while (right < nums.size()) {
            currSum += nums[right];
            while (currSum >= target) {
                minLen = min(minLen, right - left + 1);
                currSum -= nums[left++];
            }
            right++;
        }
        return minLen <= nums.size() ? minLen : 0;
    }
};