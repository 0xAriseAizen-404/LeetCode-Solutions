class Solution {
    // HashMap<Integer, Integer> hMap = new HashMap<>();
    public int fib(int n) {
        // if(hMap.contains(n)) return hMap[n];
        return fibb(n);
    }
    public static int fibb(int n) {
        if(n==0||n==1) return n;
        return (fibb(n-1) + fibb(n-2));
    }
}