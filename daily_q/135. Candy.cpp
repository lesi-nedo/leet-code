#include <vector>
#include <iostream>

using namespace std;

int compt_candies(const int& num_chs) {
    return (num_chs * (num_chs + 1))/2;
}
void add_on_bump(int& candies, int& count_small, int& count_big) {
    if (count_small > 0) {
        if (count_big > 0) {
            candies += compt_candies(max(count_big, count_small));
            candies += compt_candies(min(count_big, count_small)-1);
            count_big = 0;
        } else
            candies += compt_candies(count_small);
        count_small = 0;
    }
}

int candy(vector<int>& ratings) {
    const auto n_ch {static_cast<int>(ratings.size())};
    auto candies {n_ch};
    int&& count_big {0};
    int&& count_small {0};
    for (int child {0}; child < n_ch-1; child++) {
        if (ratings[child] == ratings[child+1]) {
            add_on_bump(candies, count_small, count_big);
            candies += compt_candies(count_big);
            count_big = 0;
        }
        if (ratings[child] < ratings[child+1]) {
            add_on_bump(candies, count_small, count_big);
            ++count_big;
        }
        if (ratings[child] > ratings[child+1])
            ++count_small;
    }
    add_on_bump(candies, count_small, count_big);
    candies += compt_candies(count_big);
    return candies;
}

int main() {
    vector<vector<int>> tests {
            // {1,0,2}
            // {100, 80, 70, 60, 70, 80, 90, 100, 90, 80, 70, 60, 60}
        // {1,3,4,5,2}
        // {1,2,87,87,87,2,1}
        {6, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0, 1, 0}
    };

    for (auto& test: tests) {
        auto res {candy(test)};

        cout << "RES: " << res << endl;
    }

    return 1;
}