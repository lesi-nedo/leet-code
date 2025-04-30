#include <vector>
#include <iostream>

using namespace std;


int countSubarrays(const vector<int>& nums) {
    int result = 0;
    const auto size_n = nums.size();

    if (size_n < 2)
        return result;

    for (size_t ind = 2; ind < size_n; ind++) {
        if (const auto sumFL = nums[ind-2] + nums[ind]; static_cast<float>(sumFL) == static_cast<float>(nums[ind-1]) / 2)
            ++result;
    }

    return result;

}


int main() {
    const vector<vector<int>> tests {
        {1,2,1,4,1},
        {1,1,1},
        {-1,-4,-1,4}
    };
    for (const auto& el: tests)
        cout << "RES: " << countSubarrays(el) << endl;
}