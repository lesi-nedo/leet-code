#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    auto size_n {nums.size()};
    vector<vector<int>>
    int needed {0};

    // ranges::sort(queries, [](const vector<int>& a, const vector<int>& b) {
    //     return a[1] - a[0] > b[1] - b[0];
    //
    // });

    vector vals (size_n, 0);
    for (auto& q: queries) {
        vals[q[0]] += 1;
        if (q[1] + 1 < size_n)
            vals[q[1]+1] -= 1;

    }
    for (size_t ind {1}; ind < size_n; ind++)
        vals[ind] += vals[ind-1];
    for (size_t ind {0}; ind < size_n; ind++)
        vals[ind] = nums[ind] - vals[ind];

    for (auto& el: vals)
        if (el > 0)
            return -1;




    for (auto& q: queries)
        cout << q[0] << " " << q[1] << endl;
    for (auto& el: vals)
        cout << el << endl;

    return static_cast<int>(size_n) - needed;
}

int main() {
    vector<pair<vector<int>, vector<vector<int>>>> tests {
        // {{0,0,1,1,0}, {{3,4},{0,2},{2,3}}},
        // {{0,1,0}, {{0,0},{0,0},{0,2},{2,2}}},
        {{0,0,1,1,0,0}, {{2,3},{0,2},{3,5}}},
        // {{1,2,3,4}, {{0,3}}},
        // {{2,0,2}, {{0,2},{0,2},{1,1}}},
        // {{1,1,1,1}, {{1,3},{0,2},{1,3},{1,2}}}
    };

    for (auto& [nums, queries]: tests) {
        const auto res {maxRemoval(nums, queries)};

        cout << "RES: " << res << endl;
    }


    return 1;
}