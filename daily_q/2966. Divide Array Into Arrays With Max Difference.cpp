#include <ranges>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>


using namespace  std;



vector<vector<int>> divideArray(vector<int>& nums, int k) {
    const auto n {nums.size()};
    vector res (n/3, vector(3, 0));
    ranges::sort(nums);
    auto curr {0};

    for (int ind {0}; ind < n; ind+=3) {
        if ( nums[ind+2] - nums[ind] >k)
            return {};
        res[curr][0] = nums[ind];
        res[curr][1] = nums[ind+1];
        res[curr][2] = nums[ind+2];
        ++curr;
    }

    return res;
}

int main() {
    vector<pair<vector<int>, int>> tests {
        {{1,3,4,8,7,9,3,5,1}, 2},
    };

    for (auto& [nums, k]: tests) {
        for (const auto res {divideArray(nums, k)}; const auto& arr: res) {
            for (const auto& el: arr)
                cout << el << " ";
            cout << endl;
        }
    }

    return 1;
}