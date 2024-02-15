class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long sum = 0;
        sort(nums.begin(),nums.end());
        for(auto x : nums) sum += x;
        for(int i = nums.size() - 1; i >= 2; i--){
            if(sum - nums[i] > nums.at(i))
                return sum;
            sum -= nums[i];
        }
        return -1;
    }
};

