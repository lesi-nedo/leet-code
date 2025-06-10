#include <vector>
#include <iostream>

using namespace std;


bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    const auto& size_q {queries.size()};
    const auto& size_n {nums.size()};

    vector all_lefts (size_n, 0);
    vector all_rights (size_n, 0);

    for (size_t ind_q = 0; ind_q < size_q; ind_q++) {
        const auto left {queries[ind_q][0]}, right {queries[ind_q][1]};
        --all_lefts[left];
        if (right + 1 < size_n                  )
            ++all_rights[right+1];
    }
    auto sum {0};
    for (size_t ind = 0; ind < size_n; ind++) {
        sum += all_lefts[ind] + all_rights[ind];
        if (nums[ind] + sum > 0)
            return false;
    }

    return true;
}

int main () {
    vector<pair<vector<int>, vector<vector<int>>>> tests {
        {{1,0,1}, {{0,2}}},

    };

    for (auto& [nums, queries]: tests) {
        const auto res {isZeroArray(nums, queries)};

        cout << "RES: " << res;
    }

    return 1;
}