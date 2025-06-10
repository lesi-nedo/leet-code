#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    const auto size {nums.size()};
    if (size  == 1) {
        return  nums[0] != 1 ? 1 : 2;
    }


    for (size_t ind = 0; ind < size; ind++) {


        if (nums[ind] > 0 && nums[ind]-1 < size && nums[ind]-1 != ind) {
            if (*(nums.begin()+nums[ind]-1) == nums[ind])
                *(nums.begin()+nums[ind]-1) = -1;
            swap(nums[ind], *(nums.begin()+nums[ind]-1));
            if (nums[ind] - 1  < size && nums[ind] - 1 != ind)
                --ind;

        }
    }
    for (auto& el: nums)
        cout << el << " ";

    cout << endl;
    for (int ind = 0; ind < size; ind++)
        if (ind != nums[ind]-1)
            return ind+1;

    return nums[size-1]+1;

}

int main() {
    vector<vector<int>> tests {
        {2,1},
        // {3,4,-1,1},
        // {1,2,0},
        // {1},
        {-3,9,16,4,5,16,-4,9,26,5,4,19,-1,25,7,22,10,-7,14,20,5,-6,11,17,3,24,-4,17,15}

    };

    for (auto& test: tests) {
        const auto res {firstMissingPositive(test)};
        cout << "RES: " << res << endl;

    }

    return 1;
}