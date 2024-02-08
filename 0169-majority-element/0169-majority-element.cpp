class Solution {
public:
    int majorityElement(vector<int>& a) {
        // int cnt = 0;
        // int ele = a[0];
        // for(int i=0;i<a.size();++i){
        //     if(ele == a[i]) cnt++;
        //     else cnt--;
        //     if(cnt==0) {
        //         cnt = 0;
        //         ele = a[i+1];
        //     }
        // }
        // return ele;
        
        int count=0;
        int ele;
        int size = a.size();
        for(int i=0;i<size;i++){
            if(count==0){
                count=1;
                ele=a[i];
            }
            else if(ele==a[i]){
                count++;
            }
            else {
                count--;
            }
        }
        count=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==ele) count++;
        }
        if(count>size/2){ 
            return ele; 
        }
        return -1;
    }
};