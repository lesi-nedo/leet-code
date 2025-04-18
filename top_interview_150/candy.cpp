


#include <vector>
#include <iostream>

using namespace std;

int to_sub(const int bigger, const int smaller) {
    cout << " smaller " << smaller << " bigger " << bigger;
    if (bigger >= 1 && smaller >= 1 && bigger >= smaller)
        return (bigger - smaller)+1;


    return 0;
}

int candy(const vector<int>& ratings) {

    const auto size = static_cast<int>(ratings.size());

    if (size <= 1)
        return size;
    if ( size <= 2 ){
        if (ratings.at(0) != ratings.at(1))
            return size+1;
        return  size;
    }

    int bigger = 0;
    int smaller = 0;
    int total  = 0;
    vector<int> candies {};
    for (auto ind = 0; ind < size-1; ind++){
        if (ratings.at(ind) > ratings.at(ind+1)) {

            ++smaller;

            candies.push_back(smaller);
            total += smaller;
        } else if (ratings.at(ind) <= ratings.at(ind+1)){

            if (smaller > 0) {
                smaller = to_sub(bigger, smaller);
                total += smaller;
                smaller = 0;
                bigger = 0;

            }

            if(ratings.at(ind) == ratings.at(ind+1)){
                smaller = 0;
                bigger = 0;
            }

            if (ratings.at(ind)  != ratings.at(ind+1) &&
                (ind + 2 == size || ind + 2 < size && ratings.at(ind+1) <= ratings.at(ind+2))) {
                ++bigger;
                candies.push_back(bigger);
                total += bigger;
            }

        }
    }
    smaller = to_sub(bigger, smaller);
    total += smaller;

    return  total+size;
}


int main(){
    constexpr int num_els = 20;
    vector<int> ratings_m [num_els] {
        {1,2,1}, // 4
        {2,1,3,4,5,6}, // 17,
        {1,5,4,3,2,1,3}, // 18
        {1,2,3,2,1}, // 9
        {1, 2,3, 4, 5, 10,8,3,2}, // 27
        {1, 2,3, 4, 5, 10,8,3,2,3}, // 29
        {1, 2,3, 4, 5, 10,8,3,2, 1}, // 31
        {1, 2,3, 4, 10,8,3,2, 1}, // 25
        {1,10,8,3,2}, // 11
        {1, 2, 10,8,3,2}, // 13
        {1, 2,3, 4, 4, 6, 10,8,3,2, 1}, // 28
        {10,8,7,3,2, 1, 2}, // 23,
        {1,2,1,2,1,2,1,2,1,2}, // 15
        {1, 0, 2}, // 5
        {1, 2, 2}, // 4
        {1,2,3,5,4,3,2,1,4,3,2,1,3,2,1,1,2,3,4}, // 47,
        {29,51,87,87,72,12}, // 12
        {1,3,4,5,2}, // 11
        {4,2,3,4,1}, // 9
        {169,311,517,4121,3946,3946} // 12

    };

    for (const auto& ratings: ratings_m){
        const auto n = candy(ratings);
        cout << "N: " << n << endl;

    }
    return 1;
}