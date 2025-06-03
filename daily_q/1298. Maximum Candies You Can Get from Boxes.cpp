#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <queue>



using namespace std;


int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int res {0};

    unordered_set<int> all_keys {};
    unordered_set<int> all_boxes {};
    queue<int> boxes_found;
    for (auto& box: initialBoxes)
        all_boxes.insert(box);
    for (auto& box: all_boxes)
        boxes_found.push(box);

    while (!boxes_found.empty()) {
        const auto box = boxes_found.front();
        boxes_found.pop();
        for (auto& new_box: containedBoxes[box]) {
            if (auto itr {all_boxes.find(new_box)}; itr == all_boxes.end()) {
                boxes_found.push(new_box);
                all_boxes.insert(new_box);
            }
        }
    }
    for (auto& box: all_boxes)
        for (auto& key: keys[box])
            if (box != key)
                all_keys.insert(key);

    for (auto& box: all_boxes) {
        if (status[box] == 1) {
            res += candies[box];
            candies[box] = 0;
        } else {
            if (auto itr {all_keys.find(box)}; itr != all_keys.end()) {
                res += candies[box];
                candies[box] = 0;
            }
        }
    }

    return res;
}


int main() {

    vector<tuple<vector<int>, vector<int>, vector<vector<int>>, vector<vector<int>>, vector<int>>> tests {
        {{1,0,1,0}, {7,5,4,100}, {{},{},{1},{}}, {{1,2},{3},{},{}}, {0}}
    };

    for (auto& [status, candies, keys, containedBoxes, initialBoxes]: tests) {
        const auto res {maxCandies(status, candies, keys, containedBoxes, initialBoxes)};

        cout << "RES: " << res << endl;
    }

    return 1;
}
