#include <iostream>
#include <vector>
#include <string>



std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
    using namespace std;
    vector<int> indices {};
    for (int ind {0}; ind < words.size(); ind++)
        if (words[ind].find(x) != string_view::npos)
            indices.push_back(ind);

    return indices;

}


int main() {
    using namespace std;
    vector<pair<vector<string>, char>> tests {

    };

    for (auto& [str, word]: tests) {
        auto res {findWordsContaining(str, word)};

        for (auto& el: res)
            cout << el << " ";
        cout << endl;
    }

}