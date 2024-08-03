class Solution {
public:
    static int compare (const void * a, const void * b)
    {
    return ( *(int*)a - *(int*)b );
    }
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        qsort(target.data(), target.size(), sizeof(int), compare);
        qsort(arr.data(), arr.size(), sizeof(int), compare);
        return target == arr;
    }
};