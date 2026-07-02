class Solution {
private:
    int partition(vector<int>& arr,int low,int high){
        int pivot=arr[low];
        int i=low,j=high;
        while(i<j){
            while(arr[i]<=pivot && i<=high-1){
                i++;
            }
            while(arr[j]>pivot&& j>=low+1){     //ErrorEncouter:: arr[j] wrong -right arr[j];
                j--;
            }
            if(i<j) swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }
    // int partition(vector<int> &nums, int low, int high) {
    //     int randomIndex = low + rand() % (high - low + 1);
    //     swap(nums[randomIndex], nums[high]);
    //     int pivot = nums[high];
    //     int noOfElementsLessThanPivot = low - 1;
    //     for (int ind = low; ind < high; ++ind) {
    //         // we assumed index {high - pivot} is the smallest element, now we try to find are there any elements less than pivot, if so we have to swap them in the starting of the recursed array, thats why we took low - 1, as our base point.
    //         // is there is a small element, then increase this index and swap it, like that we do so
    //         // if in case from low to high-1, we couldn't find any elements that are smaller than pivot then this index won't increase, it stays low - 1. and then we swap this with swap(index+1, pivot), so that all the higher elements will be on its right side
    //         if (nums[ind] <= pivot) {
    //             noOfElementsLessThanPivot += 1;
    //             swap(nums[ind], nums[noOfElementsLessThanPivot]);
    //         }
    //     }
    //     // Now we traversed the loop
    //     // if noOfElementsLessThanPivot, is now low - 1, then that means we found some smaller elements than pivot, so that next index will be the correct index for pivot i.e, noOfElementsLessThanPivot + 1
    //     // i.e, Smaller elements (we swaped above) - Pivot - Larger elements
        
    //     // if noOfElementsLessThanPivot is same low - 1, then we couldn't find any smaller elements, all the elements from low to high - 1 are larger than pivot, then that means the order should be Pivot - Larger Elements. pivot should be at start instead of high.
    //     // as noOfElementsLessThanPivot = low - 1, low is the starting index of this recursed array, then the next index is the Original pivot index i.e, noOfElementsLessThanPivot + 1

    //     swap(nums[noOfElementsLessThanPivot + 1], nums[high]);
    //     return noOfElementsLessThanPivot + 1;
    // }
    void quickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(nums, low, high);
            quickSort(nums, low, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, high);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};