#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

bool is_pal(const string_view s) {
    return std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

pair<long, long> helper(const long long& num, long long& res) {

    for (long long n_1 {num}; n_1 >= 3ll; n_1--)
        for (long long n_2 {n_1}; n_2 >= 4ll; n_2--)
            if (const auto mult {n_1*n_2}; is_pal(to_string(mult))) {
                res = mult;
                return {n_1, n_2};
            }
    res = 9;
    return {9,9};
}


int largestPalindrome(int n) {
    long long num{9};
    long long res {0};
    for (int d {0}; d < n-1; d++ )
        num = num * 10 + 9;
    auto [n1, n2] = helper(num, res);
    cout << "DIFF: " << n1 - n2 << " RES: " << res << " N1: " << n1 << " N2: " << n2 <<  endl;
    unordered_set<long long> mults {};
    for (long long n_1 {n1-1}; n_1 >= n2+1; n_1--) {
        for (long long n_2{n_1}; n_2 > n2+1; n_2--) {
            auto mult {n_1*n_2};

            if ( is_pal(to_string(mult))) {
                res = max(mult, res);
                cout << "MUL: " << mult << " n1:  " << n_1 << " n2: " << n_2 << endl;
                n2=n_2;
            }
        }
        ++n2;
    }
    return static_cast<int>(res%1337);
}

int main() {

    const vector<int> tests {
        8,
    };

    for (auto& n: tests) {
        const auto res {largestPalindrome(n)};

        cout << "RES: " << res << endl;
    }

    return 1;
}