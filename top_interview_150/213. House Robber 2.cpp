#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int computeMax(const vector<int>& starting, const size_t size) {
    int max = 0;
    for (size_t ind = 0; ind < size; ind++) {

    }
}

int rob(const vector<int>& nums) {
    const auto size = nums.size();
    const vector<pair<int, int>> value_ind;

    for (size_t ind = 0; ind < size; ind++) {
        value_ind.push_back(make_pair(nums[ind], ind));
        // TODO: create the vector with value-ind, order than take the maximum and other that are not in conflict.
        // or two for loops for the first, second and third element to find the maximum (exploring all possibles)
    }

}


int main() {
    const vector<vector<int>> tests{
        {1, 2, 3, 1},
        {2, 3, 2},
        {1, 2, 3},
        {1, 200, 2, 1, 5000, 2}
    };

    for (const auto& test: tests) {
        cout << "RES: " << rob(test) << endl;
    }

    return 1;
}