#include <vector>
#include <iostream>
#include <optional>
#include <unordered_map>

using namespace std;


int lengthOfLongestSubstring(string& s) {
    const auto size_s {s.size()};
    vector<optional<string::iterator>> els (127, nullopt);

    if (size_s <= 1)
        return static_cast<int>(size_s);

    ptrdiff_t left {0};
    els[s[left]] = s.begin();

    int curr_max = 1;
    int total_max = 1;

    for (long ind = 1; ind < size_s; ind++) {

        if (els[s[ind]] != nullopt){
            const auto dup_num {((els[s[ind]].value() + 1) - (s.begin() + left)) + left};
            total_max = max(curr_max, total_max);
            while (left < dup_num) {
                els[s[left++]] = nullopt;
            }
            curr_max = static_cast<int>((s.begin() + ind) - (s.begin() + left));
        }
        els[s[ind]] = s.begin() + ind;
        ++curr_max;
    }
    total_max = max(total_max, curr_max);


    return total_max;
}

int main () {

    vector<string> tests {
        "pwwkew",
        // "12dab240hgk",
        // "aaaaaaaabbbbbbbbcccccccc",
        // "!@#$%^&*()",
        // "a b c a b c",
        // "abcabcbb",
        // "bbbbb"

    };

    for (string &test: tests) {
        const auto res {lengthOfLongestSubstring(test)};

        cout << "RES: " << res << endl;
    }

    return 1;
}



