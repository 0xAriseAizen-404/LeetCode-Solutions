class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int m = INT_MIN;
        int a=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(prices[i]<prices[j]){
                    a=prices[j]-prices[i];
                m=max(m,a);
                }
                else break;  
            }
        }
        if(m<=0)return 0;
        else return m;
    }
};