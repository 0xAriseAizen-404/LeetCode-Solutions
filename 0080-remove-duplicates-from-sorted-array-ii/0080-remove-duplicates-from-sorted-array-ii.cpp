class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        if (n == 0) return 0;
        int count = 1;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[k] == nums[i]) {
                count++;
                if (count > 2) continue;
                nums[++k] = nums[i];
            } else {
                nums[++k] = nums[i];
                count = 1;
            }
        }
        return k+1;
    }
};