#include <array>
#include <climits>
#include <vector>
#include <iostream>
#include <queue>

#define MAX_NUM 6

using namespace std;

int best_sq(const int& curr_sq, vector<int>& mem, const vector<vector<int>>& board, const vector<array<int,2>>& tb, const int& total) {
    queue<pair<int,int>> els {};

    els.emplace(curr_sq, 0);
    mem[curr_sq] = 0;
    int final_rolls {INT_MAX};
    while (!els.empty()) {
        auto [sq, count] = els.front();
        els.pop();

        if (board[tb[sq][0]][tb[sq][1]] != -1) {
            sq = board[tb[sq][0]][tb[sq][1]]-1;
        }
        if (sq == total) {
            final_rolls = min(final_rolls, count);
        }

        for (int roll {1}; roll <= min(MAX_NUM, total-sq); roll++) {
            if (mem[sq+roll] == -1 ) {
                mem[sq+roll] = count+1;
                els.emplace(sq+roll, count+1);
            }
        }

    }

    return final_rolls == INT_MAX ? -1 : final_rolls;
}

int snakesAndLadders(const vector<vector<int>>& board) {
    const auto n_b {static_cast<int>(board.size())};
    const auto total {n_b*n_b};
    vector tb (total, array<int,2> ());
    vector mem (total, -1);
    int i {n_b-1};
    int j {0};
    int sign {1};
    for (size_t ind {0}; ind < total; ind++) {
        tb[ind][0] = i;
        tb[ind][1] = j;
        j += 1*sign;
        if (j == n_b) {
            sign = -1;
            j = n_b-1;
            --i;
        }
        if (j == -1) {
            sign = 1;
            j = 0;
            --i;
        }

    }


    return best_sq(0, mem, board, tb, total-1);
}

int main() {
    vector<vector<vector<int>>>&& boards {
        // {{-1, -1}, {-1,3}},
            // {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}},
            // {{-1,1,2,-1},{2,13,15,-1},{-1,10,-1,-1},{-1,6,2,8}},
            // {{-1,-1,27,13,-1,25,-1},{-1,-1,-1,-1,-1,-1,-1},{44,-1,8,-1,-1,2,-1},{-1,30,-1,-1,-1,-1,-1},{3,-1,20,-1,46,6,-1},{-1,-1,-1,-1,-1,-1,29},{-1,29,21,33,-1,-1,-1}},
            // {{-1,83,-1,46,-1,-1,-1,-1,40,-1},{-1,29,-1,-1,-1,51,-1,18,-1,-1},{-1,35,31,51,-1,6,-1,40,-1,-1},{-1,-1,-1,28,-1,36,-1,-1,-1,-1},{-1,-1,-1,-1,44,-1,-1,84,-1,-1},{-1,-1,-1,31,-1,98,27,94,74,-1},{4,-1,-1,46,3,14,7,-1,84,67},{-1,-1,-1,-1,2,72,-1,-1,86,-1},{-1,32,-1,-1,-1,-1,-1,-1,-1,19},{-1,-1,-1,-1,-1,72,46,-1,92,6}},
                // {{1,1,-1},{1,1,1},{-1,1,1}},
        // {{-1,1,2,-1},{2,13,15,-1},{-1,10,-1,-1},{-1,6,2,8}},
            {{-1,-1,19,10,-1},{2,-1,-1,6,-1},{-1,17,-1,19,-1},{25,-1,20,-1,-1},{-1,-1,-1,-1,15}},
        {{-1,-1,27,13,-1,25,-1},{-1,-1,-1,-1,-1,-1,-1},{44,-1,8,-1,-1,2,-1},{-1,30,-1,-1,-1,-1,-1},{3,-1,20,-1,46,6,-1},{-1,-1,-1,-1,-1,-1,29},{-1,29,21,33,-1,-1,-1}}
    };

    for (auto& test: boards) {
        auto res {snakesAndLadders(test)};
        cout << "RES: " << res << endl;
    }
    return 1;
}