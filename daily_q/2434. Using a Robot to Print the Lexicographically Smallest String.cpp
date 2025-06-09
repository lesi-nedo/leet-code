#include <vector>
#include <iostream>
#include <utility>
#include <bitset>

using namespace std;
#define MAX_LEN 100001
#define S_TYPE 0
#define L_TYPE 1

void typeMap(bitset<MAX_LEN>& type_map, const string_view s, const int& n) {
    type_map[n] = S_TYPE;
    type_map[n-1] = L_TYPE;

    for (int ind {n-2}; ind >= 0; ind--) {
        if (s[ind] > s[ind+1] || (s[ind] == s[ind+1] && type_map[ind+1] == L_TYPE))
            type_map[ind] = L_TYPE;
        else
            type_map[ind] = S_TYPE;

    }

}

void get_buck_tails(vector<int>& buck_tail, const vector<int>& buck_size, const int& np) {
    buck_tail.resize(np);
    int offset {1};
    for (size_t ind {0}; ind < np; ind++) {
        offset += buck_size[ind];
        buck_tail[ind] = offset-1;
    }
}

bool isLMSChar(const int& offset, const bitset<MAX_LEN>& type_map) {
    if (offset == 0)
        return false;
    if (type_map[offset] == S_TYPE && type_map[offset-1] == L_TYPE)
        return true;
    return false;
}

void partLMSSort(vector<int> buck_tails, vector<int>& partLMS, const string_view s, const bitset<MAX_LEN>& type_map, const int& np) {

    for (int ind {0}; ind <np-1; ind++) {
        if (!isLMSChar(ind, type_map))
            continue;
        const auto buck_ind {s[ind]-'a'};
        partLMS[buck_tails[buck_ind]] = ind;
        buck_tails[buck_ind] -= 1;
    }

    partLMS[0] = np-1;


}

void induceSortL(vector<int>& partLMS, vector<int> buckHeads, const string_view s, const bitset<MAX_LEN>& type_map ) {

    for (int ind {0}; ind < partLMS.size(); ind++) {
        if (partLMS[ind] == -1)
            continue;

        const auto ind_j {partLMS[ind] - 1};

        if (ind_j < 0 || type_map[ind_j] != L_TYPE)
            continue;
        const auto buck_ind {s[ind_j]-'a'};
        partLMS[buckHeads[buck_ind]] = ind_j;
        buckHeads[buck_ind] += 1;

    }
}

void induceSortS(vector<int>& partLMS, vector<int> buckTails, const string_view s, const bitset<MAX_LEN>& type_map ) {
    for (int ind {static_cast<int>(partLMS.size())-1}; ind >=0; ind--) {
        const auto ind_j = partLMS[ind] - 1;
        if (ind_j < 0 || type_map[ind_j] != S_TYPE)
            continue;

        const auto buck_ind = s[ind_j] - 'a';
        partLMS[buckTails[buck_ind]] = ind_j;
        buckTails[buck_ind] -= 1;

    }
}

bool lmsSubStrEqual(const string_view s, const int& n, const bitset<MAX_LEN>& type_map, const int& offsetA, const int& offsetB) {
    if (n == offsetA || n == offsetB)
        return false;

    auto ind {0};

    while (true) {
        auto aIsLMS {isLMSChar(ind+offsetA, type_map)};
        auto bIsLMS {isLMSChar(ind+offsetB, type_map)};

        if (ind > 0 && aIsLMS && bIsLMS)
            return true;
        if (aIsLMS != bIsLMS || s[ind+offsetA] != s[ind+offsetB])
            return false;
        ++ind;
    }
}

int summariseSuffixArray(
    vector<int>& summary_str, vector<int>& summary_suff_offsets, const vector<int>& partLMS, const string_view s,
    const bitset<MAX_LEN>& type_map, const int& np
) {
    vector lms_names (np, -1);
    auto curr_name {0};
    auto lastLMSSufOffset {partLMS[0]};
    lms_names[partLMS[0]] = curr_name;

    for (int ind {1}; ind < partLMS.size(); ind++) {
        const auto suffix_offset = partLMS[ind];

        if (!isLMSChar(suffix_offset, type_map))
            continue;
        if (!lmsSubStrEqual(s, np-1, type_map, lastLMSSufOffset, suffix_offset))
            curr_name += 1;
        lastLMSSufOffset = suffix_offset;
        lms_names[suffix_offset] = curr_name;

    }
    for (int ind{0}; ind<np; ind++) {
        if (lms_names[ind] == -1)
            continue;
        summary_str.push_back(lms_names[ind]);
        summary_suff_offsets.push_back(ind);
    }
    return curr_name+1;

}

void makeSummarySuffixArray(vector<int>& summary_suff_arr,  const vector<int>& summary_str, int& summary_alph_size ) {
    if (summary_alph_size == summary_str.size()) {
        summary_suff_arr[0] = static_cast<int>(summary_str.size());
        for (int ind {0}; ind<summary_str.size(); ind++)
            summary_suff_arr[summary_str[ind]+1] = ind;

    } else {
        robotWithString()
    }
}

string robotWithString(string s) {
    const auto n {static_cast<int>(s.size())};
    const auto np {n+1};
    bitset<MAX_LEN> type_map;
    typeMap(type_map, s, n);

    vector buck_size (26, 0);
    for (const auto& el: s)
        buck_size[el-'a'] += 1;
    vector buck_heads (26, 0);
    int offset = 1;
    for (size_t ind {0}; ind < np; ind++) {

        buck_heads[ind] += offset;
        offset += buck_size[ind];
    }

    vector partLMS (np, -1);
    vector<int> buck_tails;
    get_buck_tails(buck_tails, buck_size, np);

    partLMSSort(buck_tails, partLMS, s, type_map, np);
    induceSortL(partLMS, buck_heads, s, type_map);
    induceSortS(partLMS, buck_tails, s, type_map);
    vector<int> summary_str {};
    vector<int> summary_suff_offsets {};
    auto summary_alph_size {summariseSuffixArray(summary_str, summary_suff_offsets, partLMS, s, type_map, np)};


    return "a";

}

int main () {
    vector<string> tests {
        "cabbage"
        // "zza",
        // "bac",
        // "bdda"
    };
    for (const auto& s: tests) {
        auto res{robotWithString(s)};
        cout << "RES: " << res << endl;
    }

    return 1;
}