public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        int[] result = new int[2];
        int[] copy = new int[len];
        for (int i = 0; i < len; i++)
            copy[i] = numbers[i];
        Arrays.sort(copy);

        for (int i = 0; i < len; i++) {
            int j = Arrays.binarySearch(copy, target - copy[i]);
            if (j >= 0) {
                for (int k = 0, t = 0; k < len; k++) {
                    if (numbers[k] == copy[i] || numbers[k] == copy[j]) {
                        result[t++] = k + 1;
                        if (t == 2)
                            return result;
                    }
                }
            }
        }
        return null;
    }
}
