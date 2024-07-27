class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mapp;
        int summ = 0;
        int count = 0;
        for(int x: nums) {
            summ += x;
            if (summ == k) count++;
            if (mapp[(summ - k)]) count += mapp[(summ - k)];
            mapp[summ]++;
        }
        return count;
    }
};