#include <vector>
#include <iostream>

using namespace std;

void gen_permutFS(const vector<int>& nums, int* max_gain, const int sum, const size_t& size, const size_t ind) {
    if (ind  >= size - 2) {
        *max_gain = max(sum, *max_gain);
        return;
    }
    gen_permutFS(nums, max_gain, sum + nums[ind+2], size, ind+2);

    if (ind + 3 < size) {
        gen_permutFS(nums, max_gain, sum + nums[ind+3], size, ind+3);
    }

}

void gen_permutT(const vector<int>& nums, int* max_gain, const int  sum, const size_t ind) {
    if (ind == 2) {
        *max_gain = max(*max_gain, sum);
        return;
    }

    if (ind == 3 || ind < 2) {
        return;
    }

    gen_permutT(nums, max_gain, sum + nums[ind-2], ind - 2);

    gen_permutT(nums, max_gain, sum + nums[ind-3], ind - 3);
}


int rob(const vector<int>& nums) {
    const auto size = nums.size();
    if (size <= 1) return nums[0];
    if (size == 2) return max(nums[0], nums[1]);
    if (size == 3) return max(nums[0], max(nums[1], nums[2]));
    int max_gain = 0;

    gen_permutFS(nums, &max_gain, nums[0], size-1, 0);
    gen_permutFS(nums, &max_gain, nums[1], size, 1);

    if (size > 4) {
        gen_permutT(nums,  &max_gain, nums[size-1], size-1);
    }

    return max_gain;

}




int main() {
    const vector<vector<int>> tests{
        {1,2,3,1},
        {155,44,52,58,250,225,109,118,211,73,137,96,137,89,174,66,134,26,25,205,239,85,146,73,55,6,122,196,128,50,61,230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,212,241,242,157,79,133,66,36,165    },
        {1, 200, 2, 1, 50, 2, 232, 1,12,423,2,1,12,323,5,2,32,2,1,3,4,2,2,2,2,3,5,5,456,56,6,34,3,2,1,4,33,34},
        {1, 2, 3, 1, 2},
        {2, 3, 2},
        {1, 2, 3},
        {1, 200, 2, 1, 5000, 2}
    };

    for (const auto& test: tests) {
        const auto result = rob(test);
        cout << "RES: " << result << endl;
    }

    return 1;
}