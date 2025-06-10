#include <bitset>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;


void gen_poss_masks(vector<bitset<10>>& all_masks, const int size, bitset<10>& curr) {
    if (size == 0) {
        all_masks.push_back(curr);
        return;
    }
    curr.reset(size-1);
    curr.reset(size-2);
    gen_poss_masks(all_masks, size-2, curr);
    curr.set(size-1);
    curr.reset(size-2);
    gen_poss_masks(all_masks, size-2, curr);
    curr.reset(size-1);
    curr.set(size-2);
    gen_poss_masks(all_masks, size-2, curr);
}

int colorTheGrid(int m, int n) {
    typedef unsigned long long ull;
    vector dp (n, vector (1 << (m*2), 0ull));

    bitset<10> gen_mask {0};


    vector<bitset<10>> all_masks {};

    gen_poss_masks(all_masks, m*2, gen_mask);

    for (auto& mask: all_masks) {
        bitset<1> skip {0};
        for (size_t ind =  m*2; ind >= 4; ind-=2) {
            if (mask[ind-1] == mask[ind-3] && mask[ind-2] == mask[ind-4])
                skip.set(0);
        }
        if (!skip.count())
            dp[0][mask.to_ulong()] = 1;
    }


    for (size_t ind_n = 1; ind_n < n; ind_n++) {

        for (auto& mask: all_masks) {
            bitset<1> skip {0};

            for (size_t ind = m*2; ind >= 4; ind -= 2) {
                if (mask[ind-1] == mask[ind-3] && mask[ind-2] == mask[ind-4])
                    skip.set(0);
            }
            if (!skip.count())
                for (auto& prev_mask: all_masks) {
                    bitset<1> prev_skip {0};
                    for (size_t ind = m*2; ind >= 4; ind -= 2)
                        if (prev_mask[ind-1] == prev_mask[ind-3] && prev_mask[ind-2] == prev_mask[ind-4]
                        )
                            prev_skip.set(0);

                    for (int ind = m*2; ind >= 2; ind-=2)
                        if (mask[ind-1] == prev_mask[ind-1] && mask[ind-2] == prev_mask[ind-2]) {
                            prev_skip.set(0);
                        }
                    if (!prev_skip.count()) {
                        dp[ind_n][mask.to_ulong()] += dp[ind_n-1][prev_mask.to_ulong()];
                        dp[ind_n][mask.to_ulong()] %= 1000000007;
                    }
                }
        }
    }

    ull res = 0;
    for (const auto& el: dp[n-1]) {
        res += el;
        res %= 1000000007;
    }

    return static_cast<int>(res);
}




int main() {

    vector<pair<int, int>> tests {
        {{5}, {10}}

    };



    for (auto& [m, n]: tests) {
        const auto res = colorTheGrid(m,n);

        cout << "RES: " << res << endl;
    }

    return 1;
}