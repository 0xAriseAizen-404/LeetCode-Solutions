class Solution {
public:
    int minOperations(string s) {
        // case 0: if the entire string is already sorted
        // bool sorted = true;
        // for (int i = 0; i < s.length(); ++i) {
        //     if (sorted && s[i] > s[i + 1]) {
        //         sorted = false;
        //         break;
        //     }
        // }
        // if (sorted) return 0;
        if (is_sorted(s.begin(), s.end())) return 0;

        // case -1: if the length of string is only 2, we can't sort the string because it has to be sorted entirely
        if (s.size() == 2) return -1;
        
        auto [mn, mx] = minmax_element(s.begin(), s.end());

        // case 1: if min character is at 0 index, then it is in correct position, and then we can just swoop the rest of the string [1, n-1] in sorted order in One Move.
        // same with max character is at n-1 index, then it is in correct position, and then we can just swoop the rest of the string [0, n-2] in sorted order in One Move.
        if (mn == s.begin() || mx == s.end() - 1) return 1;

        // case 3: if min char is at end pos and max char is at first pos, then here we can sort one end like [0, n-2]. now max is at n-2 and min is at n-1. now sort [1, n-1] now max is at n-1 and min is at 1. now sort [0, n-2] now min will be at 0. 3 Moves
        // "rcda" -> sort 'rcd' -> "cdra" -> sort 'dra' -> "cadr" -> sort 'cad' -> "acdr"
        if (mx == s.begin() && mn == s.end() - 1) return 3;

        // case 2: if min character or max character is at middle of the string [1, n-2] indices, then we can sort the one edge to make min or max char any one of them to the correct position, then apply case 1 for the rest of the string.
        // "card" here a and r at the middle, first we can sort "ca" then it will be "acrd", now we can sort "crd" as 'a' is in correct position, now "acdr" -> 2 moves.
        return 2;
    }
};