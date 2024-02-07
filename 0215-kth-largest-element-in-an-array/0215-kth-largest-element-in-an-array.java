class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> que = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b.compareTo(a);
            }
        });
        for(int x : nums) que.add(x);
        while(k > 1) { que.poll(); k--; }
        return que.peek();
    }
}