class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        double avgSum = 0;
        double maxAvgSum = INT_MIN;
        
        for (int i = left; i < right; i++) {
            avgSum += (double)nums[i] / k;
        }
        
        maxAvgSum = max(maxAvgSum, avgSum);
        
        while (right < nums.size()) {
            avgSum += (double)(nums[right] - nums[left]) / k;
            maxAvgSum = max(maxAvgSum, avgSum);
            right++;
            left++;
        }
        
        return maxAvgSum;
    }
};
