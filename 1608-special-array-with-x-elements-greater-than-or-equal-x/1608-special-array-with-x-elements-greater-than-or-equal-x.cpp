class Solution {
public:
      int insert_pos(int x,vector<int>& nums){
        int low = 0;
        int high = nums.size()-1;
        while(low<= high){
            int mid = low +(high-low)/2;
            if(nums[mid]>=x){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return nums.size()-low; 
      }
    int specialArray(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int low = 0;
      
      int high = nums.size();
      while(low <= high){
          int mid = low +(high-low)/2;
          int b = insert_pos(mid,nums);
          if(b == mid ){
              return mid; 
          }
          if(b > mid){
              low = mid+1;
          }else{
              high = mid-1;
          }
      }
    return -1;}
};