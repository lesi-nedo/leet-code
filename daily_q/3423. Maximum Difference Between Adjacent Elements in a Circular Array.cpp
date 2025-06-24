#include <vector>
#include <iostream>

using namespace std;

int maxAdjacentDistance(const vector<int>& nums) {
    const auto n {nums.size()};
    int max_abs_diff {0};
    for (size_t ind {0}; ind < n; ind++)
        max_abs_diff = max(max_abs_diff, abs(nums[ind]-nums[(ind+1)%n]));
    return max_abs_diff;
}

int main() {

    const vector<vector<int>> tests {
        {1,2,4},
        {-5,-10,-5}
    };

    for (auto& nums: tests) {
       const  auto res {maxAdjacentDistance(nums)};

        cout << "RES: " << res << endl;
    }

    return 1;
}