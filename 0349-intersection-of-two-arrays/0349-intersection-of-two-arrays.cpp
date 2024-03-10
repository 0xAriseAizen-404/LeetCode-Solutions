// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         vector<int> ans;
//         int i=0, j=0;
//         while(i<nums1.size() && j<nums2.size()){
//             if(nums1[i]==nums2[j]){
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//             else if(nums1[i]<nums2[j]) i++;
//             else j++;
//             while(i>0 && nums1[i]==nums1[i-1]) i++;
//             while(j>0 && nums2[j]==nums2[j-1]) j++;
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n && j<m){
            //this will help to remove the duplicate entries
            if(i > 0 && nums1[i]==nums1[i-1]){
                i++;
                continue;
            }
            //helps to push the elements in the array
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            //increments if element of the other array is smaller
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
