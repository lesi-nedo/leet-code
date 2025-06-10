#include <vector>
#include <iostream>


using namespace std;


void helper(vector<int>::iterator& last_pos, vector<int>& nums, const int& el, const size_t& size) {
    vector<vector<int>::iterator> all_pos {};

    for (auto ind = last_pos - nums.begin(); ind < size; ind++) {
        if (nums[ind] == el)
            all_pos.emplace_back(next(nums.begin(), ind));
    }
    for (auto& pos: all_pos) {
        swap(*last_pos, *pos);
        ++last_pos;
    }
}

void sortColors(vector<int>& nums) {
    const auto size = nums.size();
    auto last_pos {nums.begin()};
    helper(last_pos, nums, 0, size);
    helper(last_pos, nums, 1, size);

}


int main() {
    vector<vector<int>> tests {
        {2,2,2,1,1,0,0,1,0,1,0,2,1,0,2,1,0,2,1,1},
        {2,2,2,2,2,1,0,0,1,1,0},
        {2,1,2,2,2,2,0,0,0},
        {2,2,1,1,0,0,0},
        {2,2,2,0,0,0,1,1,1},
        {0,0,0,1,1,1,2,2,2},
        {0,1,2,0,0,1,0,1,2,1,2,1,2,1,0,1,1,0,1,0,1,0,1,2,0,1,2,2,2,2,2,2,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,2,2,2,2,2,2,1,0,2,0,2,1,2,0,1,2,0}
    };

    for (auto& test: tests) {
        sortColors(test);
        cout << "[";
        for (const auto& el: test)
            cout << el << ", ";
        cout << "]" << endl;
    }
    return 1;
}