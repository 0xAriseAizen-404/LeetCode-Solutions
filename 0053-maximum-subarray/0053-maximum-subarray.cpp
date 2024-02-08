class Solution {
public:
    int maxSubArray(vector<int> &nums){
        int sum = 0;
        int max_sum = INT_MIN;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if(sum < 0) sum = 0;
        }
        return max_sum;
    }
};


    // int maxSubArray(vector<int>& nums) {
    //     int n = size(nums), ans = INT_MIN;
    //     for(int i = 0; i < n; i++) 
    //         for(int j = i, curSum = 0; j < n ; j++) 
    //             curSum += nums[j],
    //             ans = max(ans, curSum);        
    //     return ans;
    // }


    // int maxSubArray(vector<int>& nums) {
    //     int max_sum = nums[0];
    //     int curr_sum = nums[0];
    //     for (int i = 1; i < nums.size(); i++) {
    //         curr_sum = max(nums[i], curr_sum + nums[i]);
    //         max_sum = max(max_sum, curr_sum);
    //     }
    //     return max_sum;
    // }
// };