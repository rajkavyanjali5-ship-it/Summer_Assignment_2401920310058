class Solution {
    public double findMaxAverage(int[] nums, int k) {

        int currentSum = 0;

        // Calculate sum of first window
        for (int i = 0; i < k; i++) {
            currentSum += nums[i];
        }

        int maxSum = currentSum;

        // Slide the window
        for (int i = k; i < nums.length; i++) {

            currentSum = currentSum + nums[i] - nums[i - k];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return (double) maxSum / k;
    }
}