class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i=0;i<=citations.size()-1;i++){
            if(i<citations[i]){
                h++;
            }
            else
                return h;
        }
        return h;
    }
};