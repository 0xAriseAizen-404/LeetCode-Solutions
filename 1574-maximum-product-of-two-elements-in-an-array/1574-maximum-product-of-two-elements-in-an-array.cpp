class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int fmi = -1; // first_max_index
        int smi = -1; // second_max_index
        for (int i=0; i<nums.size(); ++i) {
            if (fmi == -1 || nums[i] >= nums[fmi]) {
                smi = fmi;
                fmi = i;
            } else if (smi == -1 || (nums[i] > nums[smi])) {
                smi = i;
            } else {
                continue;
            }
        }
        return (nums[fmi] - 1) * (nums[smi] - 1);

        // int max1 = INT_MIN;
        // int max2 = INT_MIN;
        // for (int x: nums) {
        //     if (x >= max1) {
        //         max2 = max1;
        //         max1 = x;
        //     } else if (x > max2) {
        //         max2 = x;
        //     }
        // }
        // return (max1 - 1) * (max2 - 1);
    }
};