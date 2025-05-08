#include <vector>
#include <iostream>


using namespace std;

vector<int> buildArray(const vector<int>& nums) {

    const auto size = nums.size();
    vector<int> result(size);

    for (size_t ind = 0; ind < size; ind++) {
        result[ind] = nums[nums[ind]];
    }

    return result;
}





int main() {
    vector<vector<int>> tests {
        {0,2,1,5,3,4},
        {5,0,1,2,3,4}
    };

    for (auto& test: tests) {
        auto result = buildArray(test);
        cout << "RES: " << "[";
        for (const auto& el: result) {
            cout << " " << el;
        }
        cout << "]" << endl;
    }


    return 1;
}

