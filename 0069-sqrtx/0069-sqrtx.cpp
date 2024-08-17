class Solution {
public:
    int mySqrt(int num) {
        int high=num,low=0;
        int ans;
        while(high>=low){
            long long int mid = low + (high - low) / 2;
            long long int sq = mid * mid;
            if(sq == num){
                return mid;
            }
            else if(sq < num)
                low = mid + 1;
            else
                high = mid -1;
        }
        return high;
    }
};