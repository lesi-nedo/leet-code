#include <cmath>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


map<int,long long> result {{0, 1}, {1, 1}, {2, 2}, {3,5}};

long long numTilings(const int n) {
    if (const auto search = result.find(n); search != result.end())
        return search->second % 1000000007;
    const auto inter_resl = 2*numTilings(n-1) + numTilings(n-3) ;
    result[n] = inter_resl;

    return inter_resl % 1000000007;
}



int main () {
    const vector<int> tests{

        {2},
        {3},
        {4},
        {5},
        {6},
        {800},
        {1000}

    };

    for (const auto& test: tests) {
        const auto result = numTilings(test);
        cout << "RESULT: " << result << endl;
    }

    return 1;
}