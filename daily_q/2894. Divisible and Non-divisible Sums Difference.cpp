#include <vector>
#include <iostream>

using namespace std;


int differenceOfSums(int n, int m) {
    int num1 {0};
    int num2 {0};
    for (int ind {1}; ind <= n; ind++) {
        if (ind % m != 0)
            num1 += ind;
        else
            num2 += ind;
    }

    return num1 - num2;
}

int main () {
    vector<pair<int, int>> tests {
        {10, 3},
        {5, 6}
    };

    for (auto& [n,m]: tests) {
        auto res {differenceOfSums(n,m)};

        cout << "RES: " << res << endl;
    }

    return 1;
}