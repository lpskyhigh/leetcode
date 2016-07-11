#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, n = strs.size();
        if (n <= 0)
            return "";
        int shortest = strs[0].size();

        for (int i = 1; i < n; ++i)
            if (strs[i].size() < shortest)
                shortest = strs[i].size();

        for (i = 0; i < shortest; ++i) {
            int j;
            for (j = 1; j < n; ++j) {
                if (strs[j][i] != strs[j - 1][i])
                    break;
            }
            
            if (j != n)
                break;
        }

        if (i == 0)
            return "";
        return strs[0].substr(0, i);
    }
};

int main() {
    vector<string> strs = { "abc", "abcd" };

    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
}
