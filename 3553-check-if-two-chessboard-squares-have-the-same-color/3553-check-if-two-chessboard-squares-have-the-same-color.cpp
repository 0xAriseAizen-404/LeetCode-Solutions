class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        bool firstOne = ((coordinate1[0]&1) == (coordinate2[0]&1));
        bool secondOne = ((coordinate1[1]&1) == (coordinate2[1]&1));
        // cout << firstOne << " " << secondOne;
        return firstOne == secondOne;
    }
};