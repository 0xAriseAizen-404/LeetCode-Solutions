class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> canHave;
        int maxx = candies[0];
        for(int x : candies) maxx = max(x, maxx);
        for(int x : candies)
            if((x+extraCandies) >= maxx) canHave.push_back(true);
            else canHave.push_back(false);
        return canHave;
    }
};