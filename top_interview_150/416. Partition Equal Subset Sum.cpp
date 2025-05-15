#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <bitset>

using namespace std;


bool canPartition(vector<int>& nums) {
    const auto size = nums.size();

    if (size < 2) return false;
    if (size == 2) return nums[0] == nums[1];

    ranges::sort(nums);
    const long long all_sum = accumulate<vector<int>::iterator, long long>(nums.begin(), nums.end(), 0);

    if (all_sum % 2 != 0)
        return false;

    long long halve = all_sum / 2;


    size_t k = 0;
    for (auto ind = static_cast<size_t>(size/2); ind >= 1; ind /= 2 ) {
        while (ind+k < size && nums[ind+k] <= halve) k += ind;
    }
    if (nums[k] == halve) {
        return true;
    }

    bitset<200001> bits;

    bits[0] = true;

    for (size_t ind = 0; ind <= k; ind++) {
        bits |= (bits << nums[ind]);
    }

    return bits[halve];

}


int main() {
    vector<vector<int>> tests {
        // {1,5,11,5},
        {23,13,11,7,6,5,5},
        // {1,1},
        // {6,14,19,10,17,10,8,15,16,1,12,4,9,2,15},
        // {4,10,7,9,7,1,11,9,13,15},
        // {9,10,15,3,9,2,9,10,13,1},
        {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,99,97},
        {6,14,19,10,17,10,8,15,16,1,12,4,9,2,15},

    };

    for (auto& test: tests) {
        auto res = canPartition(test);
        cout << "RES: " << res << endl;
    }
    return 1;
}