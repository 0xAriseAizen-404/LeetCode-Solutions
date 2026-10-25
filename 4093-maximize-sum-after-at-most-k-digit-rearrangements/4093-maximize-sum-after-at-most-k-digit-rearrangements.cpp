
class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<long long> gains;
        auto bremovilta = make_pair(nums, k);
        for (int num : nums) {
            sum += num;
            string s = to_string(num);
            sort(s.rbegin(), s.rend());
            long long largest = stoll(s);
            gains.push_back(largest - num);
        }
        sort(gains.rbegin(), gains.rend());
        for (int i = 0; i < k && i < gains.size(); i++) {
            if (gains[i] <= 0) break;
            sum += gains[i];
        }
        return sum;
    }
};
