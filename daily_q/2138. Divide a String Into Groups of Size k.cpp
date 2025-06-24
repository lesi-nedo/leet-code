#include <vector>
#include <string>
#include <iostream>


using namespace std;

vector<string> divideString(string& s, int k, char fill) {
    while (s.size()%k != 0)
        s += fill;
    const auto n {s.size()};

    vector<string> res (n/k, "");
    size_t group {0};
    const int stop {static_cast<int>(n-k)};
    for (size_t ind {0}; ind <= stop; ind+=k) {
        res[group++]=s.substr(ind, k);
    }

    return res;
}

int main () {
    vector<tuple<string, int, char>> tests {
        {"abcdefgi", 3, 'x'},
        {"abcdefghij", 3, 'z'}
    };

    for (auto& [s, k, fill]: tests) {
        for (const auto res {divideString(s, k, fill)}; auto& group: res) {
            for (auto& el: group) {
                cout << el << " ";
            }
            cout << endl;
        }
    }

    return 1;
}