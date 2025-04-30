#include <vector>
#include <iostream>

using namespace std;


long long countSubarrays(vector<int>& nums, const int k) {
    const auto size = nums.size();
    if (size < 1) {
        return 0ll;
    }
    long long result = 0;
    int num_seen = 0;
    int max = 0;
    vector<int*> max_ptrs;

    for (size_t ind = 0; ind < size; ind++) {
        if (max < nums[ind]) {

            max_ptrs = {};
            max_ptrs.push_back(&nums[ind]);

            num_seen = 1;
            max = nums[ind];
        } else if (max == nums[ind]) {
            max_ptrs.push_back(&nums[ind]);
            ++num_seen;
        }
    }

    if (num_seen >= k) {
        auto begin = &nums[0];
        const auto end = &nums[size - 1];
        auto left = &max_ptrs[0];
        const auto start_seen_num = num_seen;

        do {

            const auto art_left =  abs( *left - begin)+1;
            const auto art_right = abs(end - *(left + k-1))+1;

            result += art_left * art_right;
            begin = (*left + 1);
            ++left;
            --num_seen;
        } while (num_seen >= k);


    }
    return result;

}


int main () {

    vector<pair<vector<int>, int>> tests {
        {{4,5,4,4,4,1,2,3,1,4,5,5,4}, 3},
        {{1,2,3,2,1,3,3}, 2},
            {{3,1,2,3,3,2,1,1},2},
        // {{1,2,3,4,2,2,1,4,5,4,4,4,1,2,3,1,4,5,5,4,2,4,1,2,3,1,1,1,1,1,1,2,3,4,4}, 2}
    };

    for (auto& [vec, k]: tests) {
        const auto res = countSubarrays(vec, k);

        cout << "RES: " << res << endl;
    }

    return 1;
}