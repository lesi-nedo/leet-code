#include <vector>
#include <iostream>

using namespace std;



long long countSubarrays(const vector<int>& nums, const long long k) {
    const auto size = nums.size();

    if (size < 1)
        return 0;

    long long result = 0;
    long long size_sub = 0;
    long long sum_sub = 0;
    bool add = false;
    long long minus = 0;

    for (size_t ind = 0; ind < size;) {
        if ((size_sub+1) * (sum_sub + nums[ind]) < k) {
            ++size_sub;
            sum_sub += nums[ind];

            ++ind;
            add = true;
        } else {
            if (add) {
                result += size_sub*(size_sub+1)/2 - minus*(minus+1)/2;
                minus = 0;
                add = false;
            }



            if (nums[ind] >= k || size_sub <= 0) {
                ++ind;
                size_sub = 0;
                sum_sub = 0;
            } else {
                const auto first_ind = max(static_cast<long long>(ind) - max(size_sub, 0ll), 0ll);
                sum_sub = max(sum_sub - nums[first_ind], 0ll);
                --size_sub;
                minus = max(static_cast<long long>(ind) - first_ind - 1, 0ll);

            }


        }
    }

    return result + size_sub*(size_sub+1)/2 - minus*(minus+1)/2;
}


int main() {

    const vector<pair<vector<int>, long long>> tests {
            // {{778,45,34,23,433,5}, 2000},
            // {{778,45,3,2,1,2,3,1,1,2,3,5,140,433,5}, 2000},
            // {{4,3,5}, 11},
        // {{2,1,4,3,5}, 10},
        // {{1,1,1}, 5},
        // {{1,3,3,5,2,4,5,7,4,4,2,1,3,6}, 10},
        {{1,3,325,34,234,4,6,7,65,3,2325,123,1,3,35,34,456,4577,567,3,23,423,12313,1,2,33,5,6,54,5745,345,3,343,5,8,789,5478,4,5,9,778,45,34,23,433,5,768,435}, 2000},
        {{423,12313,1,2,33,5,6,54,5745,345,3,343,5,8,789,5478,4,5,9,778,45,34,23,433,5,768,435}, 2000},
        {{4823,9138,256,316,686,4510,2792,2519,6246,4975,7659,1174,553,1727,7539,4884,7222,465,784,5057,2614,2596,9216,2585,4698,9172,3189,1618,3677,318,2821,4575,3030,6190,181,318,3374,6117,8680,3939,7214,1624,9769,831,3596,4223,4846,8748,4774,6161,2955,941,8132,3660,2979,8997,8746,4905,7477,5356,4871,7979,7509,5128,2035,508,7211,6552,1719,7067,7906,3312,9585,9771,6,2632,3777,3959,2871,785,4622,4368,2023,822,6430,9421,8038,2821,20,4455,7996,406,1908,2265,586,586,7355,1031,6640,8036,6599,2707,2878,3531,3389,1378,7074,4740,8767,1977,8971,5739,3220,3985,6223,1544,3613,5637,5380,240,6157,205,8177,1606,9383,3865,6646,1452,6555,2309,3690,9719,7327,1947,9372,6605,1703,3042,1784,8494,8702,9288,8251,8956,4634,54},6105009866}
    };

    for (const auto&[fst, snd]: tests) {
        const auto res = countSubarrays(fst, snd);
        cout << "RES: " << res << endl;
    }

    return 1;
}