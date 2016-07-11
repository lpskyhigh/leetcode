#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int max = 0;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > max)
                max = area;
            if (height[i] <= height[j]) {
                ++i; 
            }
            else {
                --j; 
            }
        }
        return max;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }
};

int main() {
    vector<int> h = { 3, 1, 2, 3 };

    cout << (new Solution())->maxArea(h) << endl;
}
