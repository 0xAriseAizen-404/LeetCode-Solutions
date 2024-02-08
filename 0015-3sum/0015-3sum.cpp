class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;++i){
            int low = i+1;
            int high = n-1;
            while(low<high){
                int x = nums[i]+nums[low]+nums[high];
                if(x==0) {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++; high--;
                    while(low<high && nums[low]==nums[low-1]) low++;
                    while(low<high && nums[high]==nums[high+1]) high--;
                }
                else if(x>0) high--;
                else low++;
            }
            while( (i+1) < n && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};