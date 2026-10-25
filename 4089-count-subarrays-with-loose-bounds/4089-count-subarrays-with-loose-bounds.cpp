// My Solution
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = -1;
        long long count = 0;
        for (int end = 0; end < nums.size(); ++end) {
            if (minK <= nums[end] && nums[end] <= maxK) {
                if (start == -1) start = end;
            } else {
                if (start != -1) {
                    long long length = end - start;
                    count += length * (length + 1) / 2;
                }
                start = -1;
            }
        }
        if (start != -1) {
            long long length = nums.size() - start;
            count += length * (length + 1) / 2;
        }
        return count;
    }
};