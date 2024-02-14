class Solution {
    public int[] rearrangeArray(int[] a) {
        int pos = 0;
        int odd = 1;
        int ans[] = new int[a.length];
        for(int x : a) {
            if(x > 0) {
                ans[pos] = x;
                pos += 2;
            } else {
                ans[odd] = x;
                odd += 2;
            }
        }
        return ans;
    }
}