#include <vector>
#include <iostream>
#include <map>
#include <functional>


using namespace std;

void helper(
    const string_view s, const size_t dir, const size_t ind, vector<int>& ks, const vector<char>&& corr_dirs,
    const vector<char>&& incor_dirs, unordered_map<char, function<void(pair<int, int> &)>> moves, vector<pair<int,int>>& all_poss, int& res
) {
    char to_move = s[ind];

    if (ks[dir] > 0 && s[ind] != corr_dirs[0] && s[ind] != corr_dirs[1]) {
        if (s[ind] == incor_dirs[0])
            to_move = corr_dirs[0];
        else if (s[ind] == incor_dirs[1])
            to_move = corr_dirs[1];
        --ks[dir];
    }

    moves[to_move](all_poss[dir]);
    res = max(abs(all_poss[dir].first) + abs(all_poss[dir].second), res);
}

int maxDistance(const string& s, const int k) {
    vector ks (4, k);
    vector<pair<int,int>> all_poss (4, {0,0});
    const unordered_map<char, function<void(pair<int, int> &)> > moves{
        {'N', [](pair<int, int> &pos) { ++pos.second; }}, {'S', [](pair<int, int> &pos) { --pos.second; }},
        {'E', [](pair<int, int> &pos) { ++pos.first; }}, {'W',[](pair<int,int>& pos) {--pos.first;}}
    };
    int res {0};


    for (size_t ind {0}; ind < s.size(); ind++) {
        // First D1 (y (N), -x (W))
        helper(s, 0, ind, ks, {'N', 'W'}, {'S', 'E'}, moves, all_poss, res);

        // Second D2 (-y (S), -x (W))
        helper(s, 1, ind, ks, {'S','W'}, {'N', 'E'}, moves, all_poss, res);

        // Third D3 (-y (S), x (E))
        helper(s, 2, ind, ks, {'S', 'E'}, {'N', 'W'}, moves, all_poss, res);

        // Forth D4 (y (N), x (E))
        helper(s, 3, ind, ks, {'N', 'E'}, {'S', 'W'}, moves, all_poss, res);
    }


    return res;
}

int main() {

    vector<pair<string, int>> tests {
        {"NNWNSSEE", 1},
    };

    for (auto& [s, k]: tests) {
        const auto res {maxDistance(s, k)};
        cout << "RES: " << res << endl;
    }

    return 1;
}
