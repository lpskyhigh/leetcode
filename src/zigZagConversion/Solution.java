public class Solution {
    public String convert(String s, int nRows) {
        String result = "";
        int len = s.length();
        if (len == 0) return result;

        for (int i = 0, seg = 2 * (nRows - 1); i < nRows && i < len; i++) {
            int n = 2 * ((nRows - i) - 1);
            int t = seg - n;
            if (n == 0 && t == 0) n = 1;
            result += s.charAt(i);
            for (int j = i + n; j < len; j += n) {
                if (n > 0) result += s.charAt(j);
                if (t > 0 && j + t < len) {
                    result += s.charAt(j + t);
                    j = j + t;
                }
                else if (j + t >= len)
                    break;
            }
        }

        return result;
    }
}
