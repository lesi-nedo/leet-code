#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> els {};
    for (auto& el: words) {
        const auto [pos, inserted] = els.insert({el, 1});
        if (!inserted)
            els[el] += 1;
    }

    string left {""};
    string right {""};
    string center {""};

    for (auto& el: words) {

        if (auto itr2 {els.find(el)}; el[0] == el[1] && itr2->second % 2 == 1) {
            center = el;
            --itr2->second;
        } else {
            string temp = el;
            ranges::reverse(temp);
            if (auto itr {els.find(temp)}; itr != els.end()) {
                if (itr->second > 0 && itr2->second > 0) {
                    right.insert(0, itr->first);
                    left += el;
                    --itr->second;
                    if (itr2 != els.end())
                        --itr2->second;
                }
            }
        }
    }

    for (auto& el: words)
        cout << "RES: " << el << endl;
    const auto res {left + center + right};
    cout << "FINAL: " << res << endl;
    return res.size();
}


int main () {
    vector<vector<string>> tests {
        {"lc","cl","gg"}
    };

    for (auto& test: tests) {
        const auto res {longestPalindrome(test)};

        cout << "RES: " << res << endl;

    }
    return 1;
}