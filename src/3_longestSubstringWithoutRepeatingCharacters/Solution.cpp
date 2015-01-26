class Solution {
public:
    int lengthOfLongestSubString(string s) {

        if (s.length == 0) return 0;
        int result = 1;

        for (int start = -1, i = 1; i < s.length; i++) {
            bool repeated = false;

            for (int j = start + 1; j < i; j++) {
                if (s[j] == s[i]) {
                    repeated = true;
                    start = j;
                    break;
                }
            }

            if (!repeated)
                result = result > (i - start) ? result : i - start;
        }

        return result;
    }
};
