class Solution {
public:
     bool containsDuplicate(vector<int>& nums) {
         unordered_map<int,int> umap;
         for(auto x : nums){
             if(umap[x]) return true;
             umap[x]++;
         }
         return false;
     }  
};