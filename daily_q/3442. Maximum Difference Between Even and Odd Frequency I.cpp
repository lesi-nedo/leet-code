#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int maxDifference(const string& s) {
    vector count (26, 0);
    int even_max {0};
    int odd_max {0};
    int even_min {INT_MAX};
    int odd_min {INT_MAX};
    for (const auto& ch: s)
        ++count[ch - 'a'];

    for (auto& c: count) {
        if (c != 0) {
            if (c % 2 == 0) {
                even_max = c > even_max ? c : even_max;
                even_min = c < even_min ? c : even_min;
            } else {
                odd_max = c > odd_max ? c : odd_max;
                odd_min = c < odd_min ? c : odd_min;
            }
        }
    }

    return max(odd_min - even_max, odd_max - even_min);
}

int main() {

    const vector<string> tests {
        // "aaaaabbc",
        "puedscfnqbxswknqxcprvwfwluqyyhjqgksgsedgmqkonwdskirfjqwrzxpbcdmvnwoedfqesdsonsmtfllrujqsxqquerzkvnvv"

    };

    for (const auto& s: tests) {
        const auto res {maxDifference(s)};
        cout << "RES: " << res << endl;
    }

    return 1;
}