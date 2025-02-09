class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> count;
        long long good_pairs = 0;
        long long total_pairs = 0;
        for (int i=0; i<nums.size(); i++) {
            total_pairs += i;
            good_pairs += count[nums[i] - i];
            count[nums[i] - i] += 1;
        }
        return total_pairs - good_pairs;
    }
};