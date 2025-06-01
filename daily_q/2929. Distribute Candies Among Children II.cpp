#include <vector>
#include <iostream>

using namespace std;

long long distributeCandies(int n, int limit) {

    long long res {0};
    const auto min_el {min(max(n - 2*limit, 0), limit)};

    vector ord_vals (max(limit - min_el, 0) + 1, 0);
    for (int ind {0}; ind+min_el <= limit; ind++)
        ord_vals[ind] = ind+min_el;

    int max_pos {min(n - 2*ord_vals[0], limit)};
    int min_pos {max(n - (ord_vals[0]+limit), 0)};
    res += max(max_pos - min_pos + 1, 0);
    for (size_t ind {1}; ind < ord_vals.size(); ind++) {
        max_pos = min(n - (ord_vals[ind] + ord_vals[0]), limit);
        min_pos = max(n - (ord_vals[ind] + limit), 0);
        res += max(max_pos - min_pos + 1, 0);
    }

    return res;
}

int main () {

    const vector<pair<int, int>> tests {
        {5,2}
    };

    for (auto& [n, lim]: tests) {
        const auto res {distributeCandies(n, lim)};

        cout << "RES: " << res << endl;
    }


    return 1;
}