#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>


using namespace std;

void print_vec(const vector<int>& nums) {
    const auto size = nums.size();

    cout << "[";
    for (size_t ind = 0; ind < size; ind++) {
        cout << nums[ind] << ",";
    }
    cout << "]" <<  endl;

}

long long comp_perm(const size_t& n) {
    if ( n < 2) return 1;
    long long total = 1;
    for (long long ind = 2; ind <= n; ind++) {
        total *= ind;
    }

    return total;
}

long long find_equib(
    const vector<int>& nums, vector<int>& comb, const vector<int>& num_inds,
    const size_t odd_k, const size_t even_k
    ) {
    long long result = 0;


    int sum1 = 0;
    int sum2 = 0;
    vector<int> other_half {};
    ranges::sort(comb);
    ranges::set_difference(num_inds,comb,back_inserter(other_half));
    for (size_t ind = 0; ind < odd_k; ind++) {
        sum1 += nums[comb[ind]];
        if (ind < even_k) {
            sum2 += nums[other_half[ind]];
        }

    }

    if (sum1 == sum2) {
        result += comp_perm(odd_k)*comp_perm(even_k);

    }


    return result;
}

void gen_combin(
    const vector<int>& nums_ints, const size_t size
    ) {
    auto halve = static_cast<size_t>(static_cast<float>(size)/2);
    vector<vector<int>> all_combs {};
    int num_equil = 0;
    auto rest = size - halve;
    vector<int> comb {};
    for (size_t ind_fi = 0; ind_fi < size-halve;  ind_fi++) {
        comb.push_back(nums_ints[ind_fi]);
        if (const auto size_comb = comb.size(); size_comb == halve) {
            all_combs.push_back(comb);
        }
    }

}

int countBalancedPermutations(const string& num) {

    vector<int> nums_i {};
    vector<int> num_inds {};
    int ind_nums = 0;

    for (const auto& digit: num) {
        nums_i.push_back(digit - '0');
        num_inds.push_back(ind_nums++);
    }

    const auto n = nums_i.size();

    if (n < 2) return 0;
    if (n == 2) return nums_i[0] == nums_i[1];

    const auto odd_halve = static_cast<size_t>(ceil(static_cast<float>(n)/2.0));
    const auto even_halve = n - odd_halve;

    vector<int> odd_comb {};
    long long res = 0;
    gen_combin(num_inds, nums_i, odd_comb, odd_halve, even_halve, n, 0, &res);

    return  static_cast<int>(res % 1000000007);

}

int main() {
    const vector<string> tests {
        // "123",
        "112",
        // "0101",
        // "325419",
        // "96509861244547846"


    };

    for (auto& test: tests) {
        auto res = countBalancedPermutations(test);
        cout << "RES: " << res << endl;
    }


    return 1;
}