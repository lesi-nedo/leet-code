#include <vector>
#include <iostream>
#include <queue>

using namespace std;


string answerString(const string_view word, int numFriends) {
    auto cmp = [](const string_view str1, const string_view str2){ return str1 < str2; };
    priority_queue<string_view, vector<string_view>, decltype(cmp)> combs(cmp);

    string_view larg (word.begin(), word.end() - (numFriends-1));


    const auto max_pos {larg.size()};
    const auto len_str {word.size()};
    if (max_pos == len_str)
        return string(larg);

    combs.push(larg);

    for (size_t ind {1}; ind < len_str; ind++) {
        larg = word.substr(ind, min(max_pos, len_str-ind));
        combs.push(larg);
    }


    return string(combs.top());
}

int main() {

    vector<pair<string, int>> tests {
        // {"dbca", 2},
        // {"gggg", 4},
        // {"gh", 1},
        {"bagj", 3},
    };

    for (auto& [word, numFriends]: tests) {
        auto res {answerString(word, numFriends)};

        cout << "RES: " << res << endl;
    }

    return 1;
}