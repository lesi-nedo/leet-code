#include <climits>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    deque<int> res {};
    int size_arr {static_cast<int>(arr.size())};
    int so_far {0};
    int left {0};
    int right {size_arr};
    int ks {0};

    for (int b {size_arr / 2}; b >=1; b /=2 ) {
        while (ks+b < size_arr && arr[ks+b] <= x) ks+=b;
    }
    if (arr[ks] != x) {
        auto dist1 = -1;
        const auto dist2 = abs(x - arr[ks]);

        if (ks+1 < size_arr)
            dist1 = abs(arr[ks+1] - x);
        if (dist1 != -1 && dist1 < dist2)
            ks += 1;
    }
    res.push_back(arr[ks]);
    ++so_far;
    left = ks-1;
    right = ks+1;
    while (so_far < k) {
        int dist1 = -1;
        int dist2 = -1;

        if (left >= 0)
            dist1 =  abs(x - arr[left]);
        if (right < size_arr)
            dist2 = abs(arr[right] - x);

        if (dist2 >= 0 && dist2 < dist1 || dist1 == -1)
            res.push_back(arr[right++]);
        else if (dist1 != -1)
            res.push_front(arr[left--]);

        ++so_far;
    }

    return  {res.begin(), res.end()};
}


int main() {

    vector<tuple<vector<int>, int, int>> tests {
        // {{1,2,3,4,5},4,3},
        {{1,1,2,3,4,5}, 4, -1}
    };
    for (auto& [arr, k, x]: tests) {
        auto res {findClosestElements(arr, k, x)};
        cout << "[";
        for (const auto el: res)
            cout << el << " " ;
        cout << " ]" << endl;

    }


    return 1;
}