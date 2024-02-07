class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> x(nums.begin(),nums.end());
        int i = 0;
        for(auto ele : x) nums[i++] = ele;
        return x.size();
    }
//     unordered_map<int,bool> m;
//     for(int i :arr){
//         if(m.count(i)>0){
//             continue;
//         }
//         m[i] = false;
//     }
//     vector<int> ans;
//     for(int i:arr){
//         if(m[i]==false){
//             ans.push_back(i);
//             m[i] = true;
//         }

//     }
//         arr=ans;
//     return ans.size();
//     }
};