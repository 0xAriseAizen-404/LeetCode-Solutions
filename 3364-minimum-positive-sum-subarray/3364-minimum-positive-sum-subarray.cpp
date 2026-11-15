#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        FAST_IO;
        int _min_sub_sum = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int _pre_sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                _pre_sum += nums[j];
                int _sub_len = j - i + 1;
                if (l <= _sub_len && _sub_len <= r && _pre_sum > 0)
                    _min_sub_sum = min(_min_sub_sum, _pre_sum);
            }
        }
        return _min_sub_sum == INT_MAX ? -1 : _min_sub_sum;
    }
};