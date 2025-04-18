#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




size_t removeElement(vector<int>& nums, const int val) {
    auto end = nums.size();

    for (int i = 0; i<end; i++){
        if (nums.at(i) == val){
            auto ind = end - 1;
            while(nums.at(ind) == val && ind > 0 && ind > i)
                --ind;
            end = ind;
            if (i != end)
                swap(nums.at(i), nums.at(end));
        }

    }
    return end;
}

int main() {
    pair<vector<int>, int> tests[13] = {
        make_pair<vector<int>, int>({3,2,2,3}, 3),
        make_pair<vector<int>, int>({0,1,2,2,3,0,4,2}, 2),
        make_pair<vector<int>, int>({}, 0),
        make_pair<vector<int>, int>({2}, 3),
        make_pair<vector<int>, int>({0,1,2,2,3,0, 5, 6, 2, 2, 4,2}, 2),
        make_pair<vector<int>, int>({0,1,2}, 2),
        make_pair<vector<int>, int>({3, 3}, 3),
        make_pair<vector<int>, int>({3, 3}, 5),
        make_pair<vector<int>, int>({4, 5}, 4),
        make_pair<vector<int>, int>({2, 2, 2}, 2),
        make_pair<vector<int>, int>({2}, 3),
        make_pair<vector<int>, int>({1}, 1),
        make_pair<vector<int>, int>({4, 5}, 5)
    };
    for (auto p: tests){
        const auto k = removeElement(p.first, p.second);
        cout << "K: " << k << " Elements: [";
        for (const auto el: p.first){
            cout << el << " ";
        }
        cout << "]" << endl;
    }
}
