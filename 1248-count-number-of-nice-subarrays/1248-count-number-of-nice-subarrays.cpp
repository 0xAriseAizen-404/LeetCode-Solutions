class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        map <int, int> mp;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i] % 2;
            if(mp.find(sum - k) != mp.end()) {
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};