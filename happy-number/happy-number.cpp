class Solution {
public:
    bool isHappy(int n) {
        map<int, int> myMap;
        int num = n;
        while(num > 1) {
            myMap[num]++;
            if(myMap[num] > 1)
                return false;
            int summ = 0;
            int rem = 0;
            while(num > 0) {
                summ += pow(num%10, 2);
                num /= 10;
            }
            num = summ;
        }
        return num==1;
    }
};