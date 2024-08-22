class Solution {
private:
    int myHelper(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int summ = 0;
        int count = 0;
        while (right < nums.size()) {
            summ += nums[right]&1;
            while (summ > k) summ -= nums[left++]&1;
            count += right - left + 1;
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // just like binary subarray - even->(0) and odd->(1)
        return myHelper(nums, k) - myHelper(nums, k - 1);
    }
};