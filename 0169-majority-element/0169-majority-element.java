class Solution {
    public int majorityElement(int[] arr) {
        int ele = arr[0];
        int count = 0;
        for(int i=0;i<arr.length;++i) {
            if(count==0) {
                count = 1;
                ele = arr[i];
            } else if(arr[i] == ele) count++;
            else count--;
        }
        count = 0;
        for(int x : arr) {
            if(ele == x) count++;
        }
        if(count > arr.length/2) return ele;
        return -1;
    }
}