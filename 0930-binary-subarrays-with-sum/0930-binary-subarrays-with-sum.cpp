// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int count = 0, n = nums.size();
//         for(int i=0;i<n;++i){
//                 int cnt = nums[i];
//                 if(cnt==goal) count++;
//             for(int j=i+1;j<=n;++j){
//                 cnt += nums[j];
//                 if(cnt==goal) count++;
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& a, int t) {
        int sum = 0,res=0;
        int n = a.size();
        unordered_map<int ,int> mp;
        mp[0]= 1;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            int d = sum-t;
            if(mp.count(d)>0)
            {
                res+=mp[d];
            }
            mp[sum]++;
        }
        
        return res;
        
    }
};

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& a, int t) {
//         int sum = 0,res=0;
//         int n = a.size();
//         unordered_map<int ,int> mp;
//         mp[0]= 1;
//         for(int i=0;i<n;i++)
//         {
//             sum+=a[i];
//             int d = sum-t;
//             if(mp.count(d)>0)
//             {
//                 res+=mp[d];
//             }
//             mp[sum]++;
//         }
        
//         return res;
        
//     }
// };