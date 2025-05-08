#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


bool comp(const int a, const int b) {
    return a > b;
}

bool recCallMax(
    vector<int>& workers, int* tasks_completed, int& task,
    vector<int>::iterator first, vector<int>::iterator second) {
    const auto size = second - first;
    if (size == 0)
        return false;

    if (size == 1 ) {
        if  (task > *first) return false;
        workers.erase(first);
        ++*tasks_completed;
        return true;
    }
    if (const auto half = size / 2; task  > *(first + half)) {
        second = first + half;

    } else {
        first += half;


    }
    return recCallMax(workers, tasks_completed, task, first, second);


}

bool recCallMin(
    vector<int>& workers, int* tasks_completed, int& task,
    vector<int>::iterator first, vector<int>::iterator second) {
    const auto size = second - first;
    if (size == 0)
        return false;

    if (size == 1 ) {
        if  (task > *first) return false;
        workers.erase(first);
        ++*tasks_completed;
        return true;
    }
    if (const auto half = size / 2; task  < *(first + half)) {
        second = first + half + 1;
        if (task  > *(first + half - 1))
            first += half;
        else
            second = first + half;


    } else {
        first += half + 1;

    }
    return recCallMin(workers, tasks_completed, task, first, second);


}


int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, const int &strength) {
    int tasks_completed = 0;

    ranges::sort(tasks, comp);
    ranges::sort(workers, comp);

    for (auto task_iter = tasks.begin(); task_iter != tasks.end() && !workers.empty(); ++task_iter) {
        auto result = recCallMax(workers, &tasks_completed, *task_iter, workers.begin(), workers.end());
        if (!result && pills > 0) {
            auto task_min_strength = (*task_iter - strength);
            result = recCallMin(workers, &tasks_completed, task_min_strength, workers.begin(), workers.end());
            if (result)
                --pills;
        }
    }


    return tasks_completed;

}

struct Test {
    vector<int> tasks;
    vector<int> workers;
    int pills;
    int strength;
};

int main() {
    vector<Test> tests{
        Test{
                {3,2,1},
                {0,3,3},
                1,
                1
            },
        {
            {5,9,8,5,9},
            {1,6,4,2,6},
            1,
            5
        },
        {
            {33,58,22,87,38},
            {84,46,17,58,98,30,56,78,48},
            0,
            74
        },
        // Test{
        //     {74,41,64,20,28,52,30,4,4,63},
        //     {38},
        //     0,
        //     68
        // },
        // Test{
        //     {3,2,1},
        //     {0,3,3},
        //     1,
        //     1
        // },
        // Test{
        //     {5,4},
        //     {0,0,0},
        //     1,
        //     5
        // },
        // Test{
        //     {10,15,30},
        //     {0,10,10,10,10},
        //     3,
        //     10
        // },
        // //
        // Test{
        //     {2,3,45,34,1,3,45,6,6,7,345,5,7,8,6,4,443,32,1,23,4,6,23,56,56,4,34,3,5,45},
        //     {1,3,63,34,4,2,2,436,54,2,213,32,43,457,56,89,9879,89,5,4,3,2,1,212,4,5,23,5,6,78,9},
        //     5,
        //     10
        // },
        Test{
            {1943,2068,4077,7832,8061,6939,6263,8917,8008,5348,8837,4753,4607,7638,9000,7222,4552,1123,9225,6896,4154,6303,3186,2325,9994,5855,8851,7377,1930,1187,5094,2689,8852,1507,1567,9575,1193,1557,8840,9075,5032,3642,6917,7968,5310,2315,7516,4776,3091,7027,1788,2007,2651,6112,4264,5644,3585,9408,7410,9605,8151,1538,6905,6759,4518,3444,5036,1589,3902,3037,1468,9179,3000,5339,6805,7394,9418,9262,2888,4708,3402,5554,8714,7393,2848,5946,9808,4301,6675,8564,6300,4359,9506,1946,9673,7412,1164,2986,2198,5144,3763,4782,8835,6994,8035,3332,2342,5243,3150,9084,6519,9798,7682,9919,7473,7686,9978,8092,9897,3985,9874,5842,9740,2145,2426,7069,8963,9250,4142,9434,1895,6559,3233,8431,6278,6748,7305,4359,2144,8009,4890,6486,7464,8645,1704,5915,9586,1394,7504,2124,3150,2051,5026,7612,3715,5757,4355,6394,3202,2777,3949,2349,7398,3029,3081,5116,5078,8048,9934,4348,8518,5201,1203,7935,5006,6388,8680,3427,6048,1957,4026,4618,4080},
            {875,2347,939,3664,3926,4555,1947,4406,4601,3502,4964,1307,4232,2968,4572,3139,2788,1847,1208,2019,4184,1664,1747,3690,4333,891,686,1959,2218,4972,806,741,1490,4529,2909,925,2040,1234,1264,1135,3640,1455,2933,3699,2856,3074,4579,2458,2090,833,4140,4534,2336,4363,1948,4546,4155,3735,3577,2780,4874,1747,4844,3482,3053,3534,549,4500,2237,2128,1554,3210,4161,2211,950,3732,2182,1148,4368,4050,1452,1015,3192,4318,3908,2590,1103,2811,2821,690,2718,3360,2659,3315,579,3108,2979,3903,4367,1906,4964,889,4803,825,2270,4794,4825,4485,4461,1639,3857,1330,3169,2425,3694,1980,2268,3002,2177,3225,2499,2517,1916,2844,760,2167,1786,3179,3222,1432,3775,4747,1764,690,3223,4684,890,2701,1045,3034,1381,1011,2150,4798,2247,1334,3058,934,2895,1484,2784,3341,4412,1748,625,2610,3488,4810,669,4275,4929,1014,2104,3111},
            122,
            3131
        },
        // Test{
        //     {1118,1009,2913,3584,1309,2780,2503},
        //     {875,2347,939,3664,3926,4232},
        //     2,
        //     313
        // },
        // Test{
        //     {5,9,8,5,9},
        //     {1,6,4,2,6},
        //     1,
        //     5
        // }

        // {
        //     {35},
        //     {83,20,4,66},
        //     3,
        //     41
        // }
//         Test{
//             {2534, 2000, 7896,4710,7581,2301,5079,4236,7276,8656,4777,1857},
// {4686,4870,772,557,1845,2788, 2899, 821,3752},
//             3,
//             1208
//         }

    };

    for (auto&[tasks, workers, pills, strength]: tests) {
        const auto result = maxTaskAssign(tasks, workers, pills, strength);

        cout << "RESULT: " << result << endl;
    }

    return 1;
}