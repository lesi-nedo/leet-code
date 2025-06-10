#include <vector>
#include  <iostream>
#include <algorithm>
#include <climits>


using namespace std;
double median(const vector<int>& arr, const size_t& a_size) {
    const auto half {a_size/2};
    if (a_size % 2 == 0)
        return (arr[half] + arr[half-1])/2.0;
    return arr[half];
}

double rec_med(
    int i, const vector<int>& small_arr, const vector<int>& big_arr, const size_t& small_size,
    const size_t& big_size, const int half
) {
    const int j {half - i};
    int a_l {INT_MIN};
    int a_r {INT_MAX};
    int b_l {INT_MIN};
    int b_r {INT_MAX};
    if (i-1 >= 0)
        a_l = small_arr[i-1];
    if (i < small_size)
        a_r = small_arr[i];
    if (j-1 >= 0)
        b_l = big_arr[j-1];
    if (j < big_size)
        b_r = big_arr[j];
    if (a_l > b_r)
        return rec_med(i-1, small_arr, big_arr, small_size, big_size, (i-1 + j + 1)/2);
    if (b_l > a_r)
        return rec_med(i+1, small_arr, big_arr, small_size, big_size, (i+1 + j + 1) / 2);
    if ((small_size + big_size) % 2 == 0)
        return (max(a_l, b_l) + min(a_r, b_r))/2.0;
    return max(a_l, b_l);
}

double findMed(vector<int>& min_arr, vector<int>& max_arr, size_t& min_size, size_t& max_size) {
    if (min_size == 0)
        return median(max_arr, max_size);
    if (max_size == 0)
        return median(min_arr, min_size);
    if (min_arr[min_size-1] < max_arr[0]) {
        ranges::move(max_arr, back_inserter(min_arr));
        return median(min_arr, min_size+max_size);
    }
    if (max_arr[max_size-1] < min_arr[0]) {
        ranges::move(min_arr, back_inserter(max_arr));
        return median(max_arr, min_size+max_size);
    }

    return rec_med(static_cast<int>(min_size) / 2, min_arr, max_arr, min_size, max_size, static_cast<int>(max_size+min_size + 1) / 2);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto size_1 {nums1.size()};
    auto size_2 {nums2.size()};

    if (size_1)
        return findMed(nums1, nums2, size_1, size_2);

    return findMed(nums2, nums1, size_2, size_1);
}

int main() {

    vector<pair<vector<int>, vector<int>>> tests {
        // {{5,6,7,8,9}, {0,1,2,3,4}},
        {{1,3}, {2}}
    };

    for (auto& [nums1, nums2]: tests) {
        const auto res {findMedianSortedArrays(nums1, nums2)};
        cout << "RES:  " << res << endl;
    }

    return 1;
}