import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> numbers = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {

            int required = target - nums[i];

            if (numbers.containsKey(required)) {
                return new int[] { numbers.get(required), i };
            }

            numbers.put(nums[i], i);
        }

        return new int[] {};
    }
}