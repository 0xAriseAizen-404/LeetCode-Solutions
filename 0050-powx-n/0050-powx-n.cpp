
// class Solution {
// public:
//     double myPow(double x, long long n) {
//         if(n==0 || x==1)
//             return 1;
//         if(x==0)
//             return 0;
//         if(n<0)
//             return myPow(1/x,abs(n));

//         return (n%2==0 ? myPow(x*x,n/2) : x*myPow(x*x,n/2));
//     }
// };

class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        if (n == 0) return 1;
        if (x == 1) return x;
         if(n<0){
            x=1/x;
            n= abs(n);
        }
        while(n>0){
            if((n & 1)==1){
                res=res*x;
            }
            x*=x;
            n=n>>1;
        }
        return res;
    }
};