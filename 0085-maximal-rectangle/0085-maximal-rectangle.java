class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0)
            return 0;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] heights = new int[cols + 1]; // Include an extra element for easier calculation
        int maxArea = 0;
        
        for (char[] row : matrix) {
            for (int i = 0; i < cols; i++) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            
            // Calculate max area using histogram method
            int n = heights.length; // Number of bars in the histogram
            
            for (int i = 0; i < n; i++) {
                for (int j = i, minHeight = Integer.MAX_VALUE; j < n; j++) {
                    minHeight = Math.min(minHeight, heights[j]);
                    int area = minHeight * (j - i + 1);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }
        
        return maxArea;
    }
}



// class Solution {
//      static int kadane(int[] sum){
//         int maxSum = Integer.MIN_VALUE;
//         int currSum = 0;
//         for(int num : sum){
//             currSum += num;
//             maxSum = Math.max(maxSum, currSum);
//             if(currSum < 0) currSum = 0;
//         }
//         return maxSum;
//     }
//     public int maximalRectangle(char[][] arr) {
//         int n = arr.length;
//         int m = arr[0].length;
//         int[] sum = new int[n];
//         int maxSum = Integer.MIN_VALUE;
//         for(int cStart=0;cStart<m;++cStart){
//             Arrays.fill(sum,0);
//             for(int cEnd=cStart;cEnd<m;++cEnd){
//                 for(int i=0;i<n;++i) sum[i] += arr[i][cEnd];
//             int currSum = kadane(sum);
//             maxSum = Math.max(maxSum, currSum);
//             }
//         }
//     return maxSum;
//     }
// }