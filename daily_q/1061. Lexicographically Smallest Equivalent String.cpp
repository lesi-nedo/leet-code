#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
#include <memory>
#include <unordered_set>
using namespace std;

void helper(int& pos_max, int& pos_min, vector<shared_ptr<pair<int, unordered_set<int>>>>& letts) {
    if (letts[pos_max]->first < letts[pos_min]->first)
        swap(pos_max, pos_min);

    for (auto ptr: letts[pos_max]->second) {
        letts[pos_min]->second.insert(ptr);
        if (pos_max != ptr)
            letts[ptr] = letts[pos_min];
    }
    letts[pos_max] = letts[pos_min];

}

string smallestEquivalentString(const string& s1, const string& s2, const string& baseStr) {
    const auto n {s1.size()};
    constexpr auto size {26};
    vector<shared_ptr<pair<int, unordered_set<int>>>> letts (size);

    for (size_t ind {0}; ind < n; ind++ ) {
        auto temp1 {s1[ind]-'a'};
        auto temp2 {s2[ind]-'a'};
        auto curr_min {min(temp1, temp2)};
        if (const auto ptr {letts[temp1] ? &letts[temp1] : &letts[temp2]}; *ptr == nullptr) {
            letts[temp1] = make_shared<pair<int, unordered_set<int>>> (make_pair(curr_min, unordered_set<int> {}));
            letts[temp2] = letts[temp1];

        } else if (letts[temp1] == nullptr || letts[temp2] == nullptr) {
            letts[temp1] = max(letts[temp1], letts[temp2]);
            letts[temp2] = letts[temp1];
            letts[temp1]->first = min(letts[temp1]->first, curr_min);
        } else {
            if (letts[temp1] != letts[temp2])
                helper(temp1, temp2, letts);
            letts[temp2]->first = min(letts[temp2]->first, curr_min);
        }
        letts[temp2]->second.insert(temp1);
        letts[temp2]->second.insert(temp2);

    }
    string res;

    for (size_t ind {0}; ind < baseStr.size(); ind++) {
        auto temp {baseStr[ind]-'a'};
        if (letts[temp])
            res += static_cast<char>(min(letts[temp]->first, temp)+'a');
        else
            res += baseStr[ind];
    }

    return res;
}

int main () {
    vector<tuple<string, string, string>> tests {
        // {"parker", "morris", "parser"},
        // {"hello", "world", "hold"},
        // {"leetcode", "programs", "sourcecode"}
        // {"dccaccbdafgeabeeghbigbhicggfbhiccfgbechdicbhdcgahi", "igfcigeciahdafgegfbeddhgbacaeehcdiehiifgbhhehhccde", "sanfbzzwblekirguignnfkpzgqjmjmfokrdfuqbgyflpsfpzbo"}
        // {"nenneefjelfbkajjmlabiejfkfiidjigdogirrngplqkfpjcnk", "podnbcmknqbkfdarngigdorlfofcegbbnbkhhgopcofjegqdqd", "yvqnetdqbqoaejikjgcmmeqcdgvektmppufeoszxquoipoyuxh"}
        {"gicimlheddadmbmhiimakmhgklliljllfgjegamichefljcdef", "jgjbjkhkliegkfdcbfcdgmeadlkgcdfkcjdmmcgliegijgjimj", "lqppdcmgachdannbaeztqoqfpimyzcdqksykgwymceogkgruey"}
    };

    for (auto& [s1, s2, baseStr]: tests) {
        auto res {smallestEquivalentString(s1, s2, baseStr)};

        cout << "RES: " << res << endl;

    }
    return 1;
}