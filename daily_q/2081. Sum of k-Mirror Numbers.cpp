#include <cmath>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

bool is_mirror_num(const deque<char>& str) {
    size_t left = 0;
    auto right = str.size()-1;
    while (left<right) {
        if (str[left] != str[right])
            return false;
        ++left;
        --right;
    }
    return true;
}

long long get_next_mirr(long long curr_num) {
    int num_digs {0};
    long long temp_num = curr_num;
    while (temp_num > 0) {
        ++num_digs;
        temp_num /= 10;
    }
    auto ind_half {(num_digs + 1)/2-1};

    string str_num = to_string(curr_num);
    auto is_even {num_digs % 2 == 0};
    bool incr {true};
    auto last_ind {num_digs-1};
    if (str_num[ind_half]-'0' == 9) {
        str_num[ind_half] = '0';
        if (is_even)
            str_num[++ind_half] = '0';

        int right = min(ind_half+1,last_ind);
        int left = max(last_ind-right,0);

        while (right <= last_ind -1 && str_num[right] == '9') {
            str_num[right++] = '0';
            str_num[left--] = '0';

        }
        if (right != ind_half && str_num[right] != '9') {
            str_num[right] = static_cast<char>(str_num[right]-'0' + 1 + '0');
            str_num[left] = str_num[right];
            incr = false;
        }

    } else {

        str_num[ind_half] = static_cast<char>((str_num[ind_half]-'0' + 1) + '0');
        if (is_even) {
            str_num[ind_half+1] = str_num[ind_half];

        }
        incr = false;
    }

    if (incr)
        return static_cast<long long>(pow(10,num_digs))+1;

    return stoll(str_num);
}


long long kMirror(const int k, int n) {
    typedef long long ll;

    ll res {1};
    --n;
    ll num = 1;
    while (n > 0) {
        num = get_next_mirr(1999991);
        cout << "NUM: " << num << endl;

        auto curr_num = num;
        deque<char> q;
        while (curr_num > 0) {
            q.push_front(static_cast<char>(curr_num % k + '0'));
            curr_num /= k;
        }
        get_next_mirr(num);
        if (is_mirror_num(q)) {
            res += num;
            --n;
        }
    }

    return res;
}

int main() {
    const vector<pair<int, int>> tests {
        {3, 7}
    };
    for (auto& [k, n]: tests) {
        const auto res {kMirror(k, n)};
        cout << "RES: " << res << endl;
    }
    return 0;
}