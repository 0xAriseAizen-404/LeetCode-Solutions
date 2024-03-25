// class Solution {
//     public List<Integer> findDuplicates(int[] numRay) {
//         List<Integer> l = new ArrayList<>();
//         if(numRay.length < 2) return l;
        
//         for (int i = 0; i < numRay.length; i++) {
//             numRay[(numRay[i] - 1) % numRay.length] += numRay.length;
//         }
        
//         for (int i = 0; i < numRay.length; i++) {
//             if (numRay[i] >= (2 * numRay.length)) 
//                 l.add(i + 1);
//         }
        
//         return l;
//     }
// }

class Solution {
    public List<Integer> findDuplicates(int[] numRay) {
        List<Integer> l = new ArrayList<>();
        if (numRay.length < 2) return l;

        for (int i = 0; i < numRay.length; i++) {
            int index = Math.abs(numRay[i]) - 1;
            if (numRay[index] < 0) {
                l.add(index + 1);
            } else {
                numRay[index] = -numRay[index];
            }
        }

        for (int i = 0; i < numRay.length; i++) {
            numRay[i] = Math.abs(numRay[i]);
        }

        return l;
    }
}
