#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <cctype>
#include <random>

using namespace std;
using u32    = uint_least32_t;
using engine = std::mt19937;


int find_target(const int& node_passed, const vector<vector<int>>& neighbors, const int& k) {
    if (k == 0)
        return 1;

    auto target {neighbors[node_passed].size() + 1};
    stack<pair<pair<int, int>, int>> nodes_ks {};
    if ( 1 < k) {
        for (auto& neighbor: neighbors[node_passed]) {
            nodes_ks.emplace(make_pair(neighbor, node_passed), 1);
        }
        while (!nodes_ks.empty()) {
            auto [nodes_pair, curr_k] {nodes_ks.top()};
            auto& [node, prev_node] = nodes_pair;

            nodes_ks.pop();
            if (curr_k + 1 < k){
                for (auto& neigh: neighbors[node])
                    if (neigh !=  prev_node)
                        nodes_ks.emplace(make_pair(neigh, node), curr_k+1);

            }
            prev_node = node;
            target += neighbors[node].size()-1;
        }
    }

    return static_cast<int>(target);

}

int get_subt_size(const int node, const int parent, const int curr_k, const int& max_k, vector<int>& sub_sizes, const vector<vector<int>>& nodes) {
    int& res = sub_sizes[node];
    res = 1;

        for (auto& nei: nodes[node]) {
            if (nei == parent) continue;
            res += get_subt_size(nei, node, curr_k+1, max_k, sub_sizes, nodes);
        }
    return res;
}

int get_max(const vector<vector<int>>& neighbors, const int& k, const size_t& size_m) {

    int max {0};

    for (int node {0}; node < size_m; node++) {
        if (const auto targ {find_target(node, neighbors, k)}; targ > max) max = targ;
    }
    return max;
}



vector<int> maxTargetNodes(const vector<vector<int>> &edges1, const vector<vector<int>> &edges2, int &k) {
    const auto size_t1 {edges1.size() + 1};
    if (k == 0)
        return vector (size_t1, 1);

    vector<int> res {};

    const auto size_t2 {edges2.size() + 1};
    vector neighbors_t2 (size_t2, vector<int> {});
    vector neighbors_t1 (size_t1, vector<int> {});
    for (auto& edge: edges2) {
        neighbors_t2[edge[0]].push_back(edge[1]);
        neighbors_t2[edge[1]].push_back(edge[0]);
    }



    for (auto& edge: edges1) {
        neighbors_t1[edge[0]].push_back(edge[1]);
        neighbors_t1[edge[1]].push_back(edge[0]);
    }


    const int t2_target {get_max(neighbors_t2, k-1, size_t2)};

    for (int node {0}; node < size_t1; node++) {
        int targets {};
        targets += find_target(node, neighbors_t1, k) + t2_target;
        res.push_back(targets);
    }


    // for (size_t ind {0}; ind < size_t2; ind++) {
    //     cout << "NODE: " << ind << " Nei: ";
    //     for (const auto& el: neighbors_t2[ind])
    //         cout << el << " ";
    //     cout << endl;
    // }

    return res;
}

int main() {

    vector<tuple<vector<vector<int>>, vector<vector<int>>, int>> tests {
        // {{{0,1},{0,2},{2,3},{2,4}}, {{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}}, 2},
        // {{{0,1},{0,2},{0,3},{0,4}}, {{0,1},{1,2},{2,3}}, 1},
        // {{{0,1}}, {{0,1}, {1,2}}, 2},
        // {{{3,0},{2,1},{5,2},{6,3},{5,4},{5,6}}, {{5,0},{1,5},{6,1},{3,6},{2,3},{4,2},{7,4},{7,8}}, 4}
        {{{5,1},{8,2},{5,3},{0,5},{4,7},{0,4},{6,0},{6,8}}, {{4,0},{2,1},{3,4},{2,3},{2,5}}, 3}
    };

    for (auto& [ed1, ed2, k]: tests) {
        auto res {maxTargetNodes(ed1, ed2, k)};

        cout << "[";
        for (const auto& el: res)
            cout << el << " ";
        cout << "]" << endl;
    }

    return 1;
}