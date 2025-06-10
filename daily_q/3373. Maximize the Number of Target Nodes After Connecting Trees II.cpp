#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void dfs(const int& node, const vector<vector<int>>& graph, int& num_even, int& num_odd, vector<int>& eo_nodes) {
    stack<pair<pair<int,int>,int>> frontier;

    for (auto& neigh: graph[node])
        frontier.emplace(make_pair(neigh, node), 1);
    ++num_even;
    eo_nodes[node] = 0;
    while (!frontier.empty()) {
        auto [nodes_pair, num_edges] = frontier.top();
        frontier.pop();
        auto& [node, parent_node] = nodes_pair;
        if (num_edges % 2 == 0) {
            ++num_even;
            eo_nodes[node] = 0;
        } else {
            ++num_odd;
            eo_nodes[node] = 1;
        }

        for (auto& neigh: graph[node])
            if (neigh != parent_node)
                frontier.emplace(make_pair(neigh, node), num_edges+1);

    }

}


vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    vector<int> res {};
    const auto size_t1 {edges1.size() + 1};
    const auto size_t2 {edges2.size() + 1};
    vector nodes_t1 (size_t1, vector<int> {});
    vector nodes_t2 {size_t2, vector<int> {}};
    vector eo_nodes (size_t2, -1);

    vector even_odd_t1 (size_t1, make_pair(0,0));

    for (auto& edge: edges2) {
        nodes_t2[edge[0]].push_back(edge[1]);
        nodes_t2[edge[1]].push_back(edge[0]);
    }

    for (auto& edge: edges1) {
        nodes_t1[edge[0]].push_back(edge[1]);
        nodes_t1[edge[1]].push_back(edge[0]);
    }
    int total_even_t2 {0};
    int total_odd_t2 {0};
    dfs(0, nodes_t2, total_even_t2, total_odd_t2, eo_nodes);
    const int max_targ = max(total_even_t2, total_odd_t2);

    int total_even_t1 {0};
    int total_odd_t1 {0};
    eo_nodes = vector (size_t1, -1);

    dfs(0, nodes_t1, total_even_t1, total_odd_t1, eo_nodes);

    for (auto& el: eo_nodes)
        cout << el << "  " << endl;

    for (int node {0}; node < size_t1; node++)
        res.push_back(max_targ + total_even_t1*(1-eo_nodes[node]) + total_odd_t1*eo_nodes[node]);

    // for (size_t node {0}; node < size_t2; node++) {
    //     cout << "Node: " << node << " --- ";
    //     for (const auto& el: nodes_t2[node])
    //         cout << el << " ";
    //     cout << endl;
    // }

    return res;
}

int main() {
    vector<pair<vector<vector<int>>, vector<vector<int>>>> tests {
        {{{0,1},{0,2},{2,3},{2,4}}, {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}}}
    };

    for (auto& [edges1, edges2]: tests) {
        auto res {maxTargetNodes(edges1, edges2)};
        cout << "[";
        for (const auto& el: res)
            cout << el << " ";
        cout << "]" << endl;
    }

    return 1;
}
