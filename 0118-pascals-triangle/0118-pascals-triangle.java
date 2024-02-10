import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) {
            return result;
        }

        if (numRows == 1) {
            List<Integer> firstRow = new ArrayList<>();
            firstRow.add(1);
            result.add(firstRow);
            return result;
        }

        result = generate(numRows - 1);
        List<Integer> prevRow = result.get(numRows - 2);
        List<Integer> currentRow = new ArrayList<>();
        currentRow.add(1);

        for (int i = 1; i < numRows - 1; i++) {
            currentRow.add(prevRow.get(i - 1) + prevRow.get(i));
        }

        currentRow.add(1);
        result.add(currentRow);

        return result;
    }
}

// import java.util.ArrayList;
// import java.util.List;

// class Solution {
//     public List<List<Integer>> generate(int numRows) {
//         List<List<Integer>> result = new ArrayList<>();
//         if (numRows == 0) {
//             return result;
//         }

//         List<Integer> firstRow = new ArrayList<>();
//         firstRow.add(1);
//         result.add(firstRow);

//         for (int i = 1; i < numRows; i++) {
//             List<Integer> prevRow = result.get(i - 1);
//             List<Integer> currentRow = new ArrayList<>();
//             currentRow.add(1);

//             for (int j = 1; j < i; j++) {
//                 currentRow.add(prevRow.get(j - 1) + prevRow.get(j));
//             }

//             currentRow.add(1);
//             result.add(currentRow);
//         }

//         return result;
//     }
// }
