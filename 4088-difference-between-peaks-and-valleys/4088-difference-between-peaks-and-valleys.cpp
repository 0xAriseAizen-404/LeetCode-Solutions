// My Solution
class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int peaks = 0;
        int valleys = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) peaks += nums[i];
            if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) valleys += nums[i];
        }
        return peaks - valleys;
    }
};