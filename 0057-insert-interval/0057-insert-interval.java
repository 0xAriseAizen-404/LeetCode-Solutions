class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> merged = new ArrayList<>();
        int i = 0;

        // Add intervals that come before the new interval
        while (i < intervals.length && intervals[i][1] < newInterval[0]) {
            merged.add(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }

        // Add the merged new interval
        merged.add(newInterval);

        // Add remaining intervals
        while (i < intervals.length) {
            merged.add(intervals[i]);
            i++;
        }
        return merged.toArray(new int[merged.size()][2]);
    }
}

// class Solution {
//     public int[][] insert(int[][] intervals, int[] newInterval) {
//         int[][] res = new int[intervals.length+1][2];
//         int i = 0;
//         for(int[] x: intervals) {
//             res[i++] = x;
//         }
//         res[intervals.length] = newInterval;
//         Arrays.sort(res, (a,b)->Integer.compare(a[0],b[0]));
//         LinkedList<int[]> list=new LinkedList<>();
//         for(int[] interval: res) {
//             if(list.isEmpty() || list.getLast()[1] < interval[0])
//                 list.add(interval);
//             else
//                 list.getLast()[1] = Math.max(list.getLast()[1], interval[1]);
//         }
//         return list.toArray(new int[list.size()][2]);
//     }
// }