
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std;

int solve(vector<int>& data) {
    int N = data.size();
    int len = N / 2;

    int min_diff = 1000000000;
    do {
        // data[:len], data[len:]

        // prefix 0
        if (len != 1 && data[0] == 0) continue;
        if (N - len != 1 && data[len] == 0) continue;

        int first = 0;
        for (int i = 0; i < len; i++)
            first = first * 10 + data[i];

        int second = 0;
        for (int i = len; i < N; i++)
            second = second * 10 + data[i];

        if (abs(first - second) < min_diff)
            min_diff = abs(first - second);
    } while (next_permutation(data.begin(), data.end()));

    return min_diff;
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    string temp;
    getline(cin, temp); // eat the endl

    while (T--) {
        string line;
        getline(cin, line);

        istringstream iss(line);
        vector<int> data;
        int inp;
        while (iss >> inp) {
            data.push_back(inp);
        }

        cout << solve(data) << endl;
    }

    return 0;
}
