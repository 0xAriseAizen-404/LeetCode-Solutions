class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorVal = 0;
        for (int i=0; i<=nums.size(); i++) xorVal ^= i;
        for (const int &x: nums) xorVal ^= x;
        return xorVal;
    }
};