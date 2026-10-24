class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        // Let's understand what is Bitwise AND Operator
        // X & Y = k
        // To get 'k', all the set bits in 'k' must also be set bit in both X and Y.
        // lets explore this two pairs, X & Y = k and P & Q = k
        // here 'k' will the bitwise answer to both pairs, that means both pairs have same set bit, so that they result in 'k'.
        // Let's get this to expand a little more, if we do X & Y & P & Q, we will get 'k', because all the set bits will be turned on eventually in that same position.

        // now, for the given question, we can do like BitWise all the misplaced values
        // why so ?, we will not touch any correct position values to swap, we only touch the misplaced values to swap, so a pair to be swapped, it must result in bitwise 'k', like that all pairs must result in same 'k'.
        // we can just do BitWise of all misplaced values, it will eventually turn on all the set bits of same bit position in all values, which result in some value, i.e, 'k'.

        int res = -1; // -1 bit format {all 1's}
        for (int ind = 0; ind < nums.size(); ++ind) {
            if (nums[ind] != ind) res &= ind;
        }
        return (res == -1 ? 0 : res);
    }
};