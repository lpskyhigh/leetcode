#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int target = 0 - nums[i] - nums[j];            

                auto it = lower_bound(nums.begin() + j + 1, nums.end(), target);

                if (it != nums.end() && *it == target) {
                    result.push_back({ nums[i], nums[j], target }); 
                }
            }
        }

        return result;
    }
};

int main() {
    vector<int> v = { 0, 0, 0, 0 };
    Solution s;

    auto result = s.threeSum(v);

    for (auto &it : result) {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
}
