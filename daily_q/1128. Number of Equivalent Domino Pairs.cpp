#include <vector>
#include <iostream>
#include <map>

using namespace std;


int numEquivDominoPairs(const vector<vector<int>>& dominoes) {
    int result = 0;
    map<string, int> elements {};
    for (auto& domino: dominoes) {
        string s_dom = to_string(domino[0])  + to_string(domino[1]);
        string rot_s_dom =  to_string(domino[1])  + to_string(domino[0]);
        if (auto search1 = elements.find(s_dom); search1 != elements.end()) {

            ++search1->second;
        } else if (auto search2 = elements.find(rot_s_dom); search2 != elements.end()) {
            ++search2->second;
        } else {
            elements[s_dom]  = 1;
        }
    }

    for (auto& [key, value]: elements) {

        if (value >= 2) {
            int interm_result = 1;
            for (int fact=value-2+1; fact<=value; fact++) {
                interm_result *= fact;
            }

            interm_result >>= 1;
            result += interm_result;
        }
    }

    return result;
}


int main() {

    const vector<vector<vector<int>>> tests {
        {{1,2},{2,1},{3,4},{5,6}},
        {{1,2},{1,2},{1,1},{1,2},{2,2}},
        {{1,2},{1,2},{1,1},{1,2},{2,2}, {1,2},{2,1},{1,2}}
    };

    for (auto& test: tests) {
        auto result = numEquivDominoPairs(test);
        cout << "RES: " << result << endl;
    }

    return 1;
}




