class Solution {
    public int[] rearrangeArray(int[] a) {
        int pos = 0;
        int neg = 1;
        int[] ans = new int[a.length];
        for(int i=0;i<a.length;++i) {
            if(a[i] > 0) {
                ans[pos] = a[i];
                pos += 2;
            } else {
                ans[neg] = a[i];
                neg += 2;
            }
        }
        return ans;
    }
}