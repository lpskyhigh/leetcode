public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        if (len == 0) return 0;
        int length = 1;
        
        for (int start = -1, i = 1; i < len; i++) {
            boolean repeated = false;
            for (int j = start + 1; j < i; j++) {
                if (s.charAt(j) == s.charAt(i)) {
                    repeated = true;
                    start = j;
                    break;
                }
            }
            if (!repeated)
                length = length > (i - start) ? length : i - start;
        }

        return length;
    }
}
