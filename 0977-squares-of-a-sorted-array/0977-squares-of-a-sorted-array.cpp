class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int ind = nums.size() - 1;
        
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            if(pow(nums[left], 2) > pow(nums[right], 2))
                ans[ind--] = pow(nums[left++], 2);
            else
                ans[ind--] = pow(nums[right--], 2);
        }
        return ans;
    }
};