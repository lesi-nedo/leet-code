#include <climits>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int minCost(vector<vector<int>>& grid) {
    queue<pair<pair<int, int>, int>> nodes {};
    const auto n {static_cast<int>(grid[0].size())};
    const auto m {static_cast<int>(grid.size())};
    const vector<pair<vector<int>, int>> moves {{{0, 1}, 1}, {{0, -1}, 2}, {{1, 0}, 3}, {{-1, 0}, 4}};
    vector visited (m, vector (n, INT_MAX));
    nodes.emplace(make_pair(0,0), 0);
    visited[0][0] = 0;
    int min_cost {INT_MAX};

    while (!nodes.empty()) {
        auto [cell, cost] {nodes.front()};
        nodes.pop();

        if (cell.first == m-1 && cell.second == n-1) {
            min_cost = min(min_cost, cost);
        } else {
            const auto cell_move {grid[cell.first][cell.second]};
            for (auto& [to_add, move]: moves) {
                auto curr_cost = move == cell_move ? cost : cost + 1;
                auto ith_pos {max(min(cell.first + to_add[0], m-1),0)};
                auto jth_pos {max(min(cell.second + to_add[1], n-1), 0)};
                if (visited[ith_pos][jth_pos] > curr_cost) {
                    nodes.emplace(make_pair(ith_pos, jth_pos), curr_cost);
                    visited[ith_pos][jth_pos] = curr_cost;
                }
            }

        }

    }

    return min_cost;

}

int main() {
    vector<vector<vector<int>>> tests {
        // {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}},
            // {{1,2},{4,3}},
            // {{2,2,2},{2,2,2}},
            // {{1,1,3},{2,2,2},{4,4,1}},
            // {{1,1,3},{3,2,2},{1,1,4}},
            {
                {3, 4, 3}, {2, 2, 2}, {2, 1, 1}, {4, 3, 2}, {2, 1, 4}, {2, 4, 1}, {3, 3, 3}, {1, 4, 2}, {2, 2, 1},
                {2, 1, 1}, {3, 3, 1}, {4, 1, 4}, {2, 1, 4}, {3, 2, 2}, {3, 3, 1}, {4, 4, 1}, {1, 2, 2}, {1, 1, 1},
                {1, 3, 4}, {1, 2, 1}, {2, 2, 4}, {2, 1, 3}, {1, 2, 1}, {4, 3, 2}, {3, 3, 4}, {2, 2, 1}, {3, 4, 3},
                {4, 2, 3}, {4, 4, 4}
            }
    };

    for (auto& grid: tests) {
        const auto res {minCost(grid)};

        cout << "RES: " << res << endl;
    }
    return 1;
}