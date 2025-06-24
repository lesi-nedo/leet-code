#include <vector>
#include <iostream>

using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    const auto n {derived.size()};
    int res {derived[0]};
    for (size_t ind {1}; ind < n; ind++)
        res ^= derived[ind];
    return res == 0;

}

int main () {
    vector<vector<int>> tests {

    };
    for (auto& derived: tests) {
        auto res {doesValidArrayExist(derived)};

        cout << "RES: " << res << endl;
    }
    return 1;
}