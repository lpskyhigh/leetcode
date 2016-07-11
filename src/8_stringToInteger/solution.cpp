#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        const char *p = str;
        while( *p == ' ') p++; // skip fronting whitespace

        bool positive = true;
        if (*p == '+' || *p == '-')
            positive = (*p++ == '+') ? true : false;
        int sign = positive ? 1 : -1;

        int result = 0;
        bool overflow = false;
        while (*p != '\0' && *p >= '0' && *p <= '9') {
            if (positive) {
                if (result > INT_MAX/10) {
                    overflow = true;
                    break;
                }
                if (result == INT_MAX/10) {
                    if (positive && (*p-'0') > INT_MAX%10) {
                        overflow = true;
                        break;
                    }
                }
            }
            if (!positive) {
                if (result < INT_MIN/10) {
                    overflow = true;
                    break;
                }
                if (result == INT_MIN/10) {
                    if (!positive && (*p-'0') > -(INT_MIN%10)) {
                        overflow = true;
                        break;
                    }
                }
            }
            result = result * 10 + sign * (*p - '0');
            p++;
        }

        if (overflow) return positive ? INT_MAX : INT_MIN;

        return result;
    }
};

int main() {
    Solution s;

    cout << s.atoi("-11919730356x") << endl;
}
