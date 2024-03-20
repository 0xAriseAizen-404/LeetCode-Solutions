class Solution {
public:
    static int gcd(int a, int b)
    {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)? 
        str1.substr(0, gcd(size(str1),size(str2))): "";
    }
};