#include <vector>
#include <iostream>

using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> key_inds;
    key_inds.reserve(nums.size());
    for (int ind {0}; ind < nums.size(); ind++)
        if (nums[ind]==key) key_inds.push_back(ind);
    vector<int> res;
    res.reserve(nums.size());

    for (int ind {0}; ind < nums.size(); ind++) {
        for (auto& k_ind: key_inds) {
            if (abs(ind - k_ind) <= k) {
                res.push_back(ind);
                break;
            }
            if (k_ind > ind)
                break;
        }
    }

    return res;
}

int main () {

    vector<tuple<vector<int>, int, int>> tests {
        {{3,4,9,1,3,9,5}, 9, 1}
    };

    for (auto& [nums, key, k]: tests) {
        for (const auto res {findKDistantIndices(nums, key, k)}; auto& el: res)
            cout << el << " " << " ";
        cout << endl;
    }

    return 1;
}