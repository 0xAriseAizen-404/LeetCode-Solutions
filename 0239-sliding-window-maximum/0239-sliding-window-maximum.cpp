class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove index of element not within the sliding window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        
        return res;
    }
};


// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         deque<int> dq;
//         for (int i=0; i<k; ++i) {
//             while (!dq.empty() && dq.front() < nums[i]) dq.pop_front();
//             dq.push_front(nums[i]);
//         }
//         res.push_back(dq.front());
//         int left = 0;
//         for (int i=k; i<nums.size(); ++i) {
//             dq.erase(nums[left]);
//             while (dq.front() < nums[i]) dq.pop_front();
//             dq.push_front(nums[i]);
//             res.push_back(dq.front());
//         }
//         return res;
//     }
// };