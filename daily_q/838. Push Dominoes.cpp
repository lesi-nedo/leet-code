#include <string>
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

string flip_curr(string* dominoes) {

    auto length = (*dominoes).length();
    if (length == 2) {
        if ((*dominoes)[0] == '.' && (*dominoes)[1] == 'L') {
            (*dominoes)[0] = (*dominoes)[1];
        } else if ((*dominoes)[0] == 'R' && (*dominoes)[1] == '.') {
            (*dominoes)[1] = (*dominoes)[0];
        }
    }
    assert(length <= 2);
    return *dominoes;
}

void unify_str(string* dominoes) {

    const auto length = (*dominoes).length();
    if (const auto half = static_cast<int>(length / 2); (*dominoes)[half] == 'L') {
        auto ind = half-1;
        while (ind >= 0 && (*dominoes)[ind] == '.') {
            (*dominoes)[ind] = 'L';
            --ind;
        }
    } else if ((*dominoes)[half] == 'R') {
        auto ind = half + 1;
        while (ind < length  && (*dominoes)[ind] == '.') {
            (*dominoes)[ind] = 'R';
            ++ind;
        }
    } else if ((*dominoes)[half] == '.') {
        if ((*dominoes)[half+1] == 'L') {
            auto ind = half;
            while (half >= 0 && (*dominoes)[ind] == '.') {
                (*dominoes)[ind] = 'L';
                --ind;
            }
        } else if ((*dominoes)[half-1] == 'R') {
            auto ind = half;
            while (half < length && (*dominoes)[ind] == '.') {
                (*dominoes)[ind] = 'R';
                ++ind;
            }
        }


    }

}

string pushDominoes(string dominoes) {
    const auto size = dominoes.length();

    size_t ind_t {0};
    size_t old_ind_t {0};
    string directions {};
    char letter_to_app {'L'};
    while (ind_t < size) {

        if (dominoes[ind_t] == '.') {
            string lett(1,letter_to_app);
            directions.append(lett);
        } else {
            if ((letter_to_app == 'L' && dominoes[ind_t] == 'L') || (letter_to_app == 'R' && dominoes[ind_t] == 'R')) {
                dominoes.replace(old_ind_t, ind_t-old_ind_t, directions);

            } else if (letter_to_app == 'L' && dominoes[ind_t] == 'R') {
                letter_to_app = {'R'};
            } else if (letter_to_app == 'R' && dominoes[ind_t] == 'L') {
                const auto local_size = (ind_t - old_ind_t);
                const auto local_half = local_size / 2;
                auto second_start_pos = old_ind_t+local_half;
                if ( local_size - local_half != local_half)
                    ++second_start_pos;

                dominoes.replace(old_ind_t, local_half, directions.substr(0, local_half));
                string to_rep (local_half, 'L');
                dominoes.replace(second_start_pos, local_half, to_rep);
                letter_to_app = {'L'};
            }


            old_ind_t = ind_t + 1;
            directions.clear();

            // if (letter_to_app == 'R' &&)
        }
        ++ind_t;
    }

    if (!directions.empty() && letter_to_app == 'R') {
        dominoes.replace(old_ind_t, ind_t - old_ind_t, directions);
    }

    return dominoes;

}



int main() {

    const vector<string> tests {
        // ".L.R...LR..L....LR......R....L.L...L.R..",
        // ".L.R...LR..L....LR......R....L.L...L.R.",
        // "R..L",
        "...L.....R...R.....",
        ".L.R...LR..L..",
        // "RR.L",
        // "..L",
        // ".L.",
        // "R."
    };

    for (auto& test: tests) {
        auto result = pushDominoes(test);
        cout << "RESULT: " << result << endl;
    }


    return 1;
}