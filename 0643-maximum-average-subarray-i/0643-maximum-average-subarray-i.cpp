class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        int windowOpening = 0;
        int sum = 0;
        int maxx = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(i >= k - 1) {
                maxx = max(maxx, sum);
                sum -= nums[windowOpening++];
            }
        }
        return (double)maxx/k;
        
//         int left = 0;
//         int right = k;
//         double avgSum = 0;
//         double maxAvgSum = INT_MIN;
        
//         for (int i = left; i < right; i++) {
//             avgSum += (double)nums[i] / k;
//         }
        
//         maxAvgSum = max(maxAvgSum, avgSum);
        
//         while (right < nums.size()) {
//             avgSum += (double)(nums[right] - nums[left]) / k;
//             maxAvgSum = max(maxAvgSum, avgSum);
//             right++;
//             left++;
//         }
        
//         return maxAvgSum;
    }
};
