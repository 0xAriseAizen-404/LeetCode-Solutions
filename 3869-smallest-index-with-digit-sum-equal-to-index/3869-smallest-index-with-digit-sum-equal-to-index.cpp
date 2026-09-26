class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        auto digits_sum = [](int number) {
            int sum = 0;
            while (number) {
                sum += number % 10;
                number /= 10;
            }
            return sum;
        };
        for (int ind = 0; ind < nums.size(); ++ind) {
            if (ind == digits_sum(nums[ind])) return ind;
        }
        return -1;
    }
};