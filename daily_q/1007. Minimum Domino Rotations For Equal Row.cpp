#include <vector>
#include <iostream>
#include <map>
#include <limits>


using namespace std;

struct Details {
    int l_eq {0};
    int l_nq {0};


};

enum DOM  {
    TOP = 0,
    BOTTOM = 1

};

int minDominoRotations(const vector<int>& tops, const vector<int>& bottoms) {

    constexpr int all_nums = 6;
    const int MAX = std::numeric_limits<int>::max();

    const auto size = tops.size();

    vector<map<int, Details>> data_str (2);
    int result = -1;



    for (int ind = 1; ind <= all_nums; ind++) {
        data_str[TOP][ind] = Details{0,0};
    }

    for (size_t ind = 0; ind < size; ind++) {

        if (tops[ind] == bottoms[ind]) {
            ++data_str[TOP][tops[ind]].l_eq;
            ++data_str[BOTTOM][bottoms[ind]].l_eq;
        } else {
            ++data_str[TOP][tops[ind]].l_nq;
            ++data_str[BOTTOM][bottoms[ind]].l_nq;
        }
    }

    for (int ind = 1; ind <= all_nums; ind++) {
        if (data_str[TOP][ind].l_eq + data_str[TOP][ind].l_nq + data_str[BOTTOM][ind].l_nq  >= size) {
            result = min(max(result, MAX), min(data_str[BOTTOM][ind].l_nq, data_str[TOP][ind].l_nq));
        }

    }

    return result;
}




int main() {
    vector<pair<vector<int>,vector<int>>> tests {
        {{2,1,2,4,2,2}, {5,2,6,2,3,2}},
        {{3,5,1,2,3}, {3,6,3,3,4}},
        {{6,1,6,4,6,6}, {5,6,2,6,3,6}}
    };

    for (auto& [tops, bottoms]: tests) {
        const  auto result = minDominoRotations(tops, bottoms);

        cout << "RES: " << result << endl;
    }
}