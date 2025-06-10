#include  <vector>
#include  <iostream>
#include <queue>

using namespace std;

string clearStars(string& s) {
    const auto ns {s.size()};
    vector pos (26, vector<size_t> {});
    priority_queue<int, vector<int>, greater<>> letts_found {};

    for (size_t ind {0}; ind < ns; ind++) {
        if (s[ind] != '*') {
            if (const auto vec_pos {s[ind]-'a'}; pos[vec_pos].empty())
                letts_found.push(vec_pos);
            pos[s[ind]-'a'].push_back(ind);
        } else {
            const auto sm {letts_found.top()};
            const auto lst_pos {pos[sm].back()};
            pos[sm].pop_back();
            s[lst_pos] = '\0';
            s[ind] = '\0';
            if (pos[sm].empty())
                letts_found.pop();
        }
    }
    string res;
    for (size_t ind {0}; ind < ns; ind++)
        if (s[ind] != '\0')
            res += s[ind];
    return res;
}

int main() {

    vector<string> tests {
        "hello*",
    };

    for (auto& s: tests) {
        auto res =  clearStars(s);
        cout << "RES: " << res << endl;
    }

    return 1;
}