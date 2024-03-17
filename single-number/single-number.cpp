// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         map<int,bool> visited;
//         int cnt;
//         for(int i=0;i<nums.size();++i){
//             cnt=0;
//             if (visited[i]==true) continue;
//             for(int j=i+1;j<nums.size();++j){
//                 if(nums[i]==nums[j])
//                 cnt++;
//             }
//             visited[i]=true;
//             cout<<cnt;
//             if(cnt==0) return nums[i];
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int res = nums[0];
//         for(int i=1;i<nums.size();i++){
//             res = res^nums[i];
//         }
//         return res;
//     }
// };

class Solution {
    public:
        int singleNumber(vector<int>& nums){
            unordered_set<int> mySet;
            for (int i = 0; i < nums.size(); ++i) {
                int x = nums[i];
                if (mySet.count(x)) {
                    mySet.erase(x);
                } else {
                    mySet.insert(x);
                }
            }

            int ans = 0;
            for (auto i : mySet) {
                ans = i;
            }

            return ans;
        }
};