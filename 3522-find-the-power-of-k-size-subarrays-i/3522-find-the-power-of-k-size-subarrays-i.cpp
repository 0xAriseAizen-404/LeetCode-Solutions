#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= nums.size() - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            bool isSortedAndConsecutive = true;
            for (int j = 1; j < k; ++j) {
                if (subarray[j] != subarray[j - 1] + 1) {
                    isSortedAndConsecutive = false;
                    break;
                }
            }
            if (isSortedAndConsecutive) {
                result.push_back(*max_element(subarray.begin(), subarray.end()));
            } else {
                result.push_back(-1);
            }
        }
        return result;
    }
};
