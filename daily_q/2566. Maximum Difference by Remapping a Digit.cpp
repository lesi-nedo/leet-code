#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int minMaxDifference(const int num) {

    int prev {0};
    int curr {0};
    int to_rep_d_max = {10};
    int curr_dig;
    int prev_mod {1};
    for (int mod {10}; ; mod *=10 ) {
        curr = num % mod;
        curr_dig = (curr - prev)/prev_mod;
        to_rep_d_max = curr_dig < 9 ?  curr_dig : to_rep_d_max;

        prev_mod = mod;
        prev = curr;
        if (num % mod == num )
            break;
    }
    int min_num {num};
    int max_num {num};
    const int to_rep_d_min = curr_dig;
    prev = 0;
    prev_mod=1;
    for (int mod {10}; ; mod *=10 ) {
        curr = num % mod;
        curr_dig = (curr - prev)/prev_mod;

        max_num = curr_dig == to_rep_d_max ? max_num + (9-to_rep_d_max)*prev_mod : max_num;
        min_num = curr_dig == to_rep_d_min ? min_num - to_rep_d_min*prev_mod: min_num;

        prev_mod = mod;
        prev = curr;
        if (num % mod == num )
            break;
    }

    return max_num-min_num;
}

int main() {

    const vector<int> tests {
        11891,
        90,
        9099929,
    };

    for (auto& num: tests) {
        const auto res {minMaxDifference(num)};

        cout << "RES: " << res << endl;
    }

    return 1;
}