#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
#include <span>
#include <string>

using namespace std;

void helper(const span<int>& view, const int& curr, const int& k, int& res) {
    for (const auto& freq: view)
        if (freq < curr)
            res += freq;
        else if (freq > curr)
            res += max(freq-curr-k, 0);
}

int minimumDeletions(const string& word, int k) {
    vector freqs (26, 0);
    for (const auto& ch: word)
        ++freqs[ch-'a'];
    int res {INT_MAX};
    ranges::sort(freqs, greater());
    size_t min_el_ind {25};
    while (freqs[min_el_ind] == 0) --min_el_ind;
    span v_freqs (freqs.data(), min_el_ind+1);

    for (size_t ind_i {0}; ind_i < v_freqs.size(); ind_i++) {
        int temp_res {0};
        helper(v_freqs.first(ind_i), v_freqs[ind_i], k, temp_res);
        helper(v_freqs.subspan(ind_i+1), v_freqs[ind_i], k, temp_res);

        if (temp_res < res)
            res = temp_res;
    }




    return res;

}

int main() {
    vector<pair<string, int>> tests {
        // {"aabcaba", 0},
        {"dabdcbdcdcd", 2}
    };

    for (auto& [word, k]: tests) {
        const auto res {minimumDeletions(word, k)};
        cout << "RES: " << res << endl;
    }
    return 1;
}