class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Increasing n - 1 elements by 1 == Decreasing one element by 1
        // so Better to make all the elements equal to minimum element
        // Before - [1, 2, 3] |||| After - [1, 1, 1]
        // Moves = sum(before) - sum(after) = sum(nums) - n * min(nums)
        int summ = accumulate(nums.begin(), nums.end(), 0);
        int min_ele = *min_element(nums.begin(), nums.end());
        return summ - nums.size() * min_ele;
    }
};