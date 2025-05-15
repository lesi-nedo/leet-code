#include <vector>
#include <iostream>
#include <optional>

using namespace std;

class Trie {
public:
    Trie() {

    }

    void insert(string word) {

    }

    bool search(string word) {

        return false;
    }

    bool startsWith(string prefix) {
        return false;
    }
};


void print_result(const vector<vector<optional<bool>>>& res) {
    for (auto& outer: res) {
        cout << "[";
        for (auto& el: outer) {
            if (!el.has_value()) {
                cout << "null, ";
            } else if (el.value() == false) {
                cout << "false, ";
            } else {
                cout << "true, ";
            }
        }
        cout << "]" << endl;
    }
}

int main() {

    vector<pair<vector<string>, vector<string>>> tests {};
    vector<vector<optional<bool>>> final {};

    for (auto [fst, snd]: tests) {
        vector<optional<bool>> res {};
        for (size_t ind = 0; ind < fst.size(); ind++) {
            Trie trie {};

            if (fst[ind] == "insert") {
                trie.insert(snd[ind]);
                res.emplace_back(std::nullopt);

            } else if (fst[ind] == "search") {
                trie.search(snd[ind]);

            } else if (fst[ind] == "startsWith") {
                trie.startsWith(fst[ind]);
            }
        }
    }


    return 1;
}