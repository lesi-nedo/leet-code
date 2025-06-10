#include <vector>
#include <iostream>
#include <bitset>

using namespace std;
vector<string> getLongestSubsequence(const vector<string>& words, const vector<int>& groups) {
    const auto size  = words.size();


    if (size <= 1)
      return vector {words[0]};

    vector<string> res {};
    for (size_t ind = 0; ind < size-1; ind++) {
        if (groups[ind] != groups[(ind+1)]) {
            res.push_back(words[ind]);
        } else {
            res.push_back(words[ind]);
            while (ind < size - 1 && groups[ind] == groups[ind+1]) ind++;
        }
    }
    if (groups[size-2] != groups[size-1]) {
        res.push_back(words[size-1]);
    }

    return res;

}

int main() {


    vector<pair<vector<string>, vector<int>>> tests {
        {{"a", "b", "c", "d", "e"}, {1, 1, 1, 1, 1}},
        {{"f", "o", "l", "i", "v", "r", "a", "q", "z", "g", "p", "h", "n", "c", "y", "u", "e", "b", "k", "t", "w", "m", "x", "j", "s", "d"},{0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0}},
        {{"zvedu", "lwdc", "hdzxskgolc", "riavnjtkkq", "rcjus", "lkdy", "t", "ogetdzwtp", "bxkr", "ul", "hql", "ajragiuuo", "n", "wve", "qrnsfj", "lxq", "kiiwtt", "ipaiguj", "dmp", "vgojlcy", "hl", "vhbylrhf", "utxz", "lc", "zg", "sny", "vkhd", "zwlzbzhuy", "e", "yay", "iuaz", "kulsuuksdi", "idzikb", "larthyyfrp", "tlzxb", "rxngmsw", "xyrbfmttf", "fgcehzw", "tksuk", "psngvcgjz", "alqrm", "bgfb", "fmbuv", "snprpzdees", "qlkofi", "yrdbyv", "y", "pnhxulzx", "yprndzrv", "yybcsdpivk", "xzljt", "tk", "anou", "tnzaszevuz", "iz", "cins", "lm", "g", "gap", "yrgowfrgv", "sawxnnnct", "unsaxygosz", "nsjlxxesm", "ujmav", "vj", "dam", "slnyvnzj", "eevhhnw", "gtqbbp", "krvzq", "memclrd", "gvwaaqrgz", "aigxxlhir", "vkbdo", "jazqnndx", "ttnai", "tkg", "iswjne", "scnr", "rm", "yjyr", "rvwo", "nvktima", "vwdqokabvb", "ahbmkhfim", "uvsvlvyvg", "rk", "ogqsoeywih", "v", "ccm", "fu", "crti", "bfvoapp", "d", "ayqulkg", "c", "vv", "qqkjaubnf", "pkhtth", "hdxmfxqpv"}, {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0}}
    };

    for (auto& [fst, scd]: tests) {
        auto res = getLongestSubsequence(fst, scd);

        for (auto& el: res) {
            cout << el << endl;
        }
    }

    return 1;
}