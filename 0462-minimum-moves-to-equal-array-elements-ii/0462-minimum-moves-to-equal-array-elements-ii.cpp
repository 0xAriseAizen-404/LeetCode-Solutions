class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // We can increment or decrement any element by 1, and make all equal
        // best choice is to choose a median, make all elements equal to median
        // moves = sigma(abs(a[i] - median))
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int moves = 0;
        for (auto& x: nums) moves += abs(x - median);
        return moves;
    }
};