#include <string>
#include <iostream>

using namespace std;

string encode(const string& message) {
    string result;
    const auto size_mesg =  message.size();
    int count = 1;
    for (size_t ind = 0; ind < size_mesg - 1; ind++) {
        if (message[ind] == message[ind+1])
            ++count;
        else {
            result += to_string(count) + message[ind];

            count = 1;
        }
    }

    result += to_string(count) + message[size_mesg - 1];

    return result;



}

string countAndSay(const int n) {
    if (n <= 1) return  "1";
    return encode(countAndSay(n - 1));

}


int main() {
    // cout << "RLE " << countAndSay(6) << endl;
    cout << "RLE: " << encode("111221") << endl;
    return 1;
}