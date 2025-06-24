#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int partitionArray(vector<int>& nums, const int k) {
    const auto n {nums.size()};
    int res {0};
    ranges::sort(nums);

    int min {INT_MAX};
    for (size_t ind {0}; ind < n; ) {
        min = nums[ind++];
        while (ind < n && nums[ind]-min <= k) ++ind;
        ++res;
    }


    return res;
}

int main() {

    vector<pair<vector<int>, int>> tests {
        {{20,1,7,2,1,10,2,16,7,8}, 15}
        // {{1,2,3}, 1},
        // {{3,6,1,2,5}, 2}
        // {{2,2,4,5}, 0}
    };

    for (auto& [nums, k]: tests) {
        auto res {partitionArray(nums, k)};
        cout << "RES: " << res << endl;
    }

    return 1;
}