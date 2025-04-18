#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, const int n) {
    int ind = 0;
    const int total_size = n + m;
    while(!nums2.empty() && ind < total_size) {
        auto it = nums1.begin();
        auto nit = it+ind;
        if ( ind >= m && nums1.at(ind) == 0){
            nums1[ind++] = nums2.front();
            nums2.erase(nums2.begin());
        } else if(nums1.at(ind) >= nums2.front()){
            nums1.insert(nit, nums2.front());
            nums2.erase(nums2.begin());
            nums1.erase(nums1.end());
            m++;
        } else {
            ind++;
        }


    }
}

int main()
{

    vector<int> nums1 = {-1, 3, 0, 0, 0, 0, 0};
    vector<int> nums2 = {0, 0, 1, 2, 3};

    const int m = 2;
    const int n = 5;
    merge(nums1, m, nums2, n);
    for (const int i : nums1) {
        std::cout << i << " ";
    }


    return 0;
}