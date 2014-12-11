public class Solution {
    public String longestPalindrome(String s) {
        int length = s.length();
        int longest = 1;
        int start = 0, end = 1;

        for (int i = 1; i < length; i++) {
            int inc = 0, j, k;
            for (j = i - longest - 1, k = i; j >= 0 && j <= k; j++, k--) {
                if (s.charAt(j) != s.charAt(k)) {
                    break;
                }
            }
            if (j > k) inc = 2;
            for (j = i - longest, k = i; j >= 0 && j <= k; j++, k--) {
                if (s.charAt(j) != s.charAt(k)) {
                    break;
                }
            }
            if (j > k) inc = 1;
            if (inc > 0) {
                start = i - longest - inc + 1;
                end = i + 1;
                longest = longest + inc;
            }
        }

        return s.substring(start, end);
    }
}
