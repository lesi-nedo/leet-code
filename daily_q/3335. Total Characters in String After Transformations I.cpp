#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;


int lengthAfterTransformations(string s, int t) {
    constexpr int first_ascii_char {97};
    constexpr int size_alphs {122 - first_ascii_char};
    const auto mod =  1000000007ll;
    long long result = 0;
    vector ds (size_alphs+1, 0ll);

    for (const auto& lett: s) {
        ++ds[lett-'a'];
    }


    for (int trans = 0; trans < t; trans++) {
        const auto z = ds[25] % mod;
        for (auto lett = 25; lett > 0; lett--) {
            ds[lett] = ds[lett-1];
        }
        ds[0] = z;
        ds[1] += z;

        result += z;
    }



    return static_cast<int>(result % 1000000007);
}



int main() {
    vector<pair<string, int>> tests {
        {"abcyy", 2},
        {"zwzzugozhwsycuocakus", 1},
        {"z", 100},
        {"hrzmawnweztcskakojfahyvnoctsctwsbagyqmmoheldlpzctduxmhfcwqcbvovoyswjtdzvsheoofocknqddfsjwxfuuhvznxry", 1000},
        {"jqktcurgdvlibczdsvnsg", 7517},
        {"xdzbhxqcmhezajdhljzsgshikospdeyxrnwylcvcuvfppquqqxcfbvmdlwbzkxjkwzvoyvmpnlxuyulexoqgayvxlvofyjhmxshfprpbhjywofbqhhufezuyccasrodkzmxkwzfhcfxhlrpidoklhgidflvyppajzgecuhumjyglgzqzcusdniuqgylpxlhkknwbwehtaabnioerjnpxxjqhmxftsoukxbfkndssniyhwqfmtcoerxrkkdjepiyrhmnepuwaunubwrixahwaoecretfzbqavlhzavdherptjpkhqrkpopdheswffikuxrvqohccbyphcrirhhjddjqihwxlszdehalyoqqzsimaaxepttwbfpbtqgwhidvzoegkjeqdhndszmrtgloqwerpdsvqhdvmfqxwdmkocqcltqiojgpstzainiukaejurbvuvjbyyodruvuliahiscdmrjmnthehnmhovjwakenmuwbxqeoox", 100000}

    };
    long long res = 1;
    pmr::unordered_map<int, long long> memory {};

    for (auto& [fst, scd]: tests) {
        const auto result {lengthAfterTransformations(fst, scd)};
        cout << "RES: " << result << endl;
    }
    return 1;
}