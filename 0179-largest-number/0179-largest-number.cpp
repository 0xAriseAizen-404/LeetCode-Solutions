class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums(nums.size());
        for (int i = 0; i < nums.size(); ++i) strNums[i] = to_string(nums[i]);
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        string res = accumulate(strNums.begin(), strNums.end(), string());
        return res[0] == '0' ? "0" : res;
    }
};
