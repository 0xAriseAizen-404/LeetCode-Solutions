class Solution {
    public void moveZeroes(int[] arr) {
      int n = arr.length;
      //finding first zero occurrence
      int k = 0;
      while (k < n) {
        if (arr[k] == 0) {
          break;
        } else {
          k = k + 1;
        }
      }
      //finding zeros and immediate non-zero elements and swapping them
      int i = k, j = k + 1;
      while (i < n && j < n) {
        if (arr[j] != 0) {
          arr[i] = arr[j];
          arr[j] = 0;
          i++;
        }
        j++;
      }
    }
}