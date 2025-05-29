#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>
#include <ranges>
#include <unordered_map>

using namespace std;


int largestPathValue(const string& colors, const vector<vector<int>> &edges) {
    const auto n {colors.size()};
    deque<int> nq {};
    vector prev_nodes_map (n, unordered_map<char, int> {});

    vector nodes (n,  make_pair(0, vector<int> {}));
    int vis_nodes {0};
    int larg_color_val {-1};

    for (auto& edge: edges) {
        nodes[edge[0]].second.push_back(edge[1]);
        ++nodes[edge[1]].first;
    }

    for (int node {0}; node < n; node++)
        if (nodes[node].first == 0) {
            nq.push_back(node);
            prev_nodes_map[node][colors[node]] = 1;
        }


    while (!nq.empty()) {
        const  auto curr_node {nq.back()};
        nq.pop_back();

        ++vis_nodes;
        if (nodes[curr_node].second.empty()) {
            for (const auto &count: prev_nodes_map[curr_node] | ranges::views::values)
                larg_color_val = max(larg_color_val, count);
        } else
            for (auto& neigh: nodes[curr_node].second) {
                for (auto& [color, count]: prev_nodes_map[curr_node])
                    prev_nodes_map[neigh][color] = max(count, prev_nodes_map[neigh][color]);

                --nodes[neigh].first;
                if (nodes[neigh].first == 0) {
                    ++prev_nodes_map[neigh][colors[neigh]];
                    for (auto& count: prev_nodes_map[neigh] | views::values)
                        larg_color_val = max(larg_color_val, count);

                    nq.push_back(neigh);
                }
            }
    }

    if (vis_nodes != n)
        return -1;

    return larg_color_val;
}


int main() {
    vector<pair<string, vector<vector<int>>>> tests {
        {"abaca", {{1,2},{0,2},{2,3},{3,4}}}
    };

    for (auto& [colors, edges]: tests) {
        const  auto res {largestPathValue(colors, edges)};

        cout << "RES: " << res << endl;
    }

    return 1;
}