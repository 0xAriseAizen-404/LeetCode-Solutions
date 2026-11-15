#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        FAST_IO;
        int _max_len = 1;
        int _inc_len = 1;
        int _dec_len = 1;
        for (int ind = 1; ind < nums.size(); ++ind) {
            if (nums[ind - 1] < nums[ind]) {
                _dec_len = 1; _inc_len += 1;
            } else if (nums[ind - 1] > nums[ind]) {
                _inc_len = 1; _dec_len += 1;
            } else {
                _inc_len = 1; _dec_len = 1;
            }
            _max_len = max({_max_len, _inc_len, _dec_len});
        }
        return _max_len;
    }
};