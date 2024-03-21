// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n==0) return 1;
//         else if (n<0){
//             n = n - 2*n;
//             return 1/(x*myPow(x,n-1));
//         }
//         else return x*myPow(x,n-1);
//     }
// };

class Solution {
public:
    double myPow(double x, long long n) {
        if(n==0 || x==1)
            return 1;
        if(x==0)
            return 0;
        if(n<0)
            return myPow(1/x,abs(n));

        return (n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x,n/2));
    }
};

/* INTEGER*/

// class Solution {
//     public:
//         double myPow(double x,int n) {
//             if(n==0) return 1;
//             int res = myPow(x ,n/2);
//             if(n & 1) return x * res * res;
//             return res * res;
//         }
// };