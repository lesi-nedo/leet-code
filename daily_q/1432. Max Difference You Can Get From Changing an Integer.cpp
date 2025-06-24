#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int maxDiff(const int num) {

    auto str {to_string(num)};
    const auto ns {str.size()};
    auto str_cp = str;
    int rep_min_pos {-1};
    int rep_max_pos {-1};
    for (int ind {0}; ind<ns; ind++) {
        if (rep_min_pos != -1 && rep_max_pos != -1)
            break;

        if (rep_max_pos == -1 && str[ind] != '9')
            rep_max_pos = ind;
        if (rep_min_pos == -1 && str[ind] != '1' || str[ind] != '0')
            rep_min_pos = ind;
    }
    rep_min_pos = rep_min_pos == -1 ? 0 : rep_min_pos;
    rep_max_pos = rep_max_pos == -1 ? 0 : rep_max_pos;
    ranges::replace(str_cp, str[rep_max_pos], '9');

    const char rep {rep_min_pos > 0 ? '0' : '1'};
    const char to_rep {str[rep_min_pos]};
    ranges::replace(str, to_rep, rep);
    return stoi(str_cp) - stoi(str);
}

int main() {

    const vector<int> tests {
        // 9,
        555,
        // 123456
    };

    for (auto& num: tests) {
        auto res {maxDiff(num)};

        cout << "RES: " << res << endl;
    }

    return 0;
}