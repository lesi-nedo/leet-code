#include <vector>
#include <iostream>
#include <optional>


using namespace std;

class WordDictionary {
public:
    WordDictionary() {

    }

    void addWord(string word) {

    }

    bool search(string word) {

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


int main () {
    vector<pair<vector<string>,vector<vector<string>>>> tests {
        {{"WordDictionary","addWord","addWord","addWord","search","search","search","search"}, {{},{"bad"}, {"dad"}, {"mad"}, {"pad"}, {"bad"}, {".ad"}, {"b.."}}},

    };
    vector<vector<optional<bool>>> res {};
    for (auto& [fst, scnd]: tests) {
        vector<optional<bool>> temp {};
        for (size_t ind = 0; ind < fst.size(); ind++) {
            WordDictionary dicts;

            if (fst[ind] == "WordDictionary") {
                dicts = {};
            } else if (fst[ind] == "addWord") {
                dicts.addWord(scnd[ind][0]);
                temp.emplace_back(std::nullopt);
            } else {

                temp.emplace_back(dicts.search(scnd[ind][0]));
            }

        }
        res.push_back(temp);
    }

    print_result(res);


    return 1;
}