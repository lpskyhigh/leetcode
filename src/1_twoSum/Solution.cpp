#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> vtoi;
        for (int i = 0; i < numbers.size(); i++) {
            vtoi[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (vtoi[target-numbers[i]]) {
                vector<int> v;
                v.push_back(i+1);
                v.push_back(vtoi[target-numbers[i]]+1);
                return v;
            }
        }
    }
};

int main() {
    vector<int> numbers;

    int target;
    cin >> target;
    int i;
    while (cin >> i)
        numbers.push_back(i);

    Solution s;
    vector<int> result = s.twoSum(numbers, target);
    cout << "index1=" << result[0] << ", index2=" << result[1] << endl;
}
