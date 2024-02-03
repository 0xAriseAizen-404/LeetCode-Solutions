class Solution {
    public void sortColors(int[] arr) {
        int low = 0, mid = 0,high = arr.length-1;
        if(high>=1){
            while(mid <= high){
                if(arr[mid] == 0) {
                    arr[mid++] = arr[low];
                    arr[low++] = 0;
                }
                else if(arr[mid] == 1) mid++;
                else {
                    arr[mid] = arr[high];
                    arr[high--] = 2;
                }
            }
        }
    }
}