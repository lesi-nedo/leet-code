#include <vector>
#include <iostream>


using namespace std;

void helper(vector<int>& res, int& fir_num, size_t& ind, int& n, const int max_val, const int bound) {

    res[ind++] = fir_num++;
    --n;
    while (res[ind-1]*10<=max_val) {
        res[ind++] = res[ind-1]*10;
        --n;
    }

    for (auto num {res[ind-1]+1}; num < bound; num++) {
        res[ind++]=num;
        --n;
    }
    fir_num=res[ind-1];
    while ((fir_num-9) % 10 == 0) fir_num = (fir_num - 9)/10+1;

}

vector<int> lexicalOrder(int n) {
    const auto max_val {n};
    vector res (n, 0);
    size_t ind {0};
    int fir_num {1};

    while (res[ind-1] < max_val) {
        helper(res, fir_num, ind, n, max_val, min(res[ind-1]+10, max_val+1));
    }
    // fir_num = res[ind-(res[ind-1]%10+2)]+1;
    // while (n > 0)
    //     helper(res, fir_num, ind, n, max_val, fir_num+min(9,n));

    return move(res);
}

int main() {
    const vector<int> tests {
        142
    };

    for (const auto& n: tests) {
        const auto res {lexicalOrder(n)};

        cout << "[";
        for (const auto& el: res)
            cout << el << " ";
        cout << "]" << endl;
    }

    return 1;
}