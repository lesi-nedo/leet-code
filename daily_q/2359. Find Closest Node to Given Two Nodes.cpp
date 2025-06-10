#include <climits>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    const int size_g {static_cast<int>(edges.size())};
    unordered_set lns {node1};
    unordered_set rns {node2};
    const int&& wait {-1};
    int& ln {node1};
    int& rn {node2};
    auto& next_ln {edges[ln]};
    auto& next_rn {edges[rn]};

    while (ln != rn) {

        int temp_ln = INT_MAX;
        int temp_rn = INT_MAX;
        if (const auto itr{rns.find(ln)}; itr != rns.end())
            temp_ln =  ln;
        if (const auto itr {lns.find(rn)}; itr != lns.end())
            temp_rn = rn;
        if (temp_ln != INT_MAX || temp_rn != INT_MAX)
            return min(temp_rn, temp_ln);

        if (next_ln == -1 && next_rn == -1) return -1;

        if (next_ln != -1) {
            if (const auto itr {lns.find(next_ln)}; itr != lns.end())
                next_ln = wait;
            else {
                lns.insert(next_ln);
                ln = next_ln;
                next_ln = edges[ln];
            }
        }
        if (next_rn != -1) {
            if (const auto itr {rns.find(next_rn)}; itr != rns.end())
                next_rn = wait;
            else {
                rns.insert(next_rn);
                rn = next_rn;
                next_rn = edges[rn];
            }
        }
    }

    return ln;

}



int main() {

    vector<tuple<vector<int>, int, int>> tests {
        // {{2,2,3,-1}, 0, 1},
        // {{1,2,-1}, 0, 2},
        // {{1,2,0,4,5,3}, 0, 2}
        // {{4,3,0,5,3,-1}, 4, 0},
        {{23,21,28,30,25,10,13,18,1,22,16,10,27,8,6,26,19,0,-1,12,11,29,2,24,4,14,17,15,5,7,9}, 28, 13}
    };

    for (auto& [edges, node1, node2]: tests) {
        const auto res {closestMeetingNode(edges, node1, node2)};

        cout << "RES: " << res << endl;
    }

    return 1;
}