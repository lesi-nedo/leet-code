#include <vector>
#include <iostream>


using namespace std;



int findNumbers(const vector<int>& nums) {
    unsigned int result = 0;

    for (int num: nums) {
        unsigned int digits = 0;

        while (num > 0) {
            ++digits;
            num /= 10;
        }

        result += digits & 1 ^ 1;
    }

    return static_cast<int>(result);
}

int main() {
    vector<vector<int>> tests {
        {99999, 12},
        {1000},
        {555},
        {12,423,555,23,34,534, 23423, 23434, 54796, 99999}
    };

    for (const auto& test: tests) {
        const auto result = findNumbers(test);
        cout << "RES: " << result << endl;

    }
}