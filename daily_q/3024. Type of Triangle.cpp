#include <bitset>
#include <vector>
#include <iostream>


using namespace std;


string triangleType(const vector<int>& nums) {
    int res = (nums[0] + nums[1] + nums[2])*(nums[0] - nums[1] + nums[2])*(nums[0] + nums[1] - nums[2])*(-nums[0] + nums[1] + nums[2]);

    if (res <= 0)
        return "none";

    bitset<7> num1 {static_cast<unsigned long long>(nums[0])};
    bitset<7> num2 {static_cast<unsigned long long>(nums[1])};
    bitset<7> num3 {static_cast<unsigned long long>(nums[2])};

    auto diff1 = num1 ^ num2;
    auto diff2 = num1 ^ num3;
    auto diff3 = num2 ^ num3;

    if (diff1 == diff2 && diff2 == diff3)
        return "equilateral";
    if (diff1 == 0 || diff2 == 0 || diff3 == 0)
        return "isosceles";
    cout << diff2 << endl;
    cout << num1 << endl << num3 << endl;
    return "scalene";
}

int main() {
    const vector<vector<int>> tests {
        {9,4,9}
        // {3,3,3},
        // {3,4,5},
        // {1, 1, 1},
        // {1, 1, 2}
    };

    for (auto& test: tests) {
        auto res = triangleType(test);
        cout << "RES: " << res << endl;
    }

    return 1;
}