#include <climits>
#include  <vector>
#include <iostream>

using namespace std;

int maximumDifference(vector<int>& nums) {
    int min_val {INT_MAX};
    int max_val {0};
    int max_diff {0};

    for (int ind {0}; ind < nums.size(); ind++) {
        if (nums[ind] < min_val) {
            max_diff = max_val - min_val > max_diff ? max_val - min_val : max_diff;
            min_val = nums[ind];
            max_val = 0;
        } else if (min_val < nums[ind] && max_val < nums[ind])
            max_val = nums[ind];
    }
    max_diff = max_val - min_val > max_diff ? max_val - min_val : max_diff;

    return max_diff ? max_diff : -1;
}

int main() {

    vector<vector<int>> tests {
        // {7,1,5,4},
        {87,68,91,86,58,63,43,98,6,40}

    };

    for (auto& nums: tests) {
        const auto res {maximumDifference(nums)};

        cout << "RES: " << res << endl;
    }

    return 1;
}