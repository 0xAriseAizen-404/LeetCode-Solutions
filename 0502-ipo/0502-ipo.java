class Solution {
    public int findMaximizedCapital(int numProjects, int initialCapital, int[] profits, int[] capital) {
        int projectIndex = 0;
        int totalProjects = profits.length;

        // Create a list of pairs where each pair consists of (capital required, profit)
        List<int[]> projects = new ArrayList<>();
        for (int i = 0; i < totalProjects; i++) {
            projects.add(new int[]{capital[i], profits[i]});
        }

        // Sort the projects based on the capital required in ascending order
        projects.sort(Comparator.comparingInt(a -> a[0]));

        // Use a max heap to keep track of the maximum profits available within the current capital
        PriorityQueue<Integer> maxProfitHeap = new PriorityQueue<>(Collections.reverseOrder());

        // Iterate through the number of projects we can undertake
        for (int currentProject = 0; currentProject < numProjects; currentProject++) {
            // Push all projects that can be started with the current capital into the max heap
            while (projectIndex < totalProjects && projects.get(projectIndex)[0] <= initialCapital) {
                maxProfitHeap.add(projects.get(projectIndex)[1]);
                projectIndex++;
            }

            // If no projects can be started, return the current capital
            if (maxProfitHeap.isEmpty()) {
                return initialCapital;
            }

            // Add the profit of the project with the maximum profit to the current capital
            initialCapital += maxProfitHeap.poll();
        }

        // Return the maximized capital after undertaking up to k projects
        return initialCapital;
    }
}