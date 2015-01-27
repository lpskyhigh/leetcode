public class Solution {
    public int reverse(int x) {
        int y = x < 0 ? -x : x;
        int result = 0;

        while (y > 0) {
            int m = y % 10;
            int t = result * 10 + m;
            if ((t - m) / 10 != result) return 0;
            result = t;
            y /= 10;
        }
        return x < 0 ? -result : result;
    }
}
