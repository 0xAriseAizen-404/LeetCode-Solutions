// class Solution {
//     public int tribonacci(int n) {
//         if (n == 0) return 0;
//         if (n == 1 || n == 2) return 1;
//         return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
//     }
// }


class Solution {
    public int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        int prev1=0,prev2=1,prev3=1,curr=0;
        for(int i=3;i<=n;i++){
            curr = prev1+prev2+prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }
        return curr;
    }
}


// class Solution {
//     public int tribonacci(int n) {
//         Map<Integer, Integer> memo = new HashMap<>();
//         return helper(n, memo);
//     }
    
//     private int helper(int n, Map<Integer, Integer> memo) {
//         if (memo.containsKey(n)) {
//             return memo.get(n);
//         }
        
//         int result;
//         if (n == 0) {
//             result = 0;
//         } else if (n == 1 || n == 2) {
//             result = 1;
//         } else {
//             result = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
//         }
        
//         memo.put(n, result);
//         return result;
//     }
// }