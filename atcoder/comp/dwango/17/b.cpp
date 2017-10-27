#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define INF 1010001000

string input;

int main()
{

    cin >> input;

    int ans = 0;
    int bef;

    if (input[0] == '?' || input[0] == '2') {
        bef = 2;
    } else {
        bef = 0;
    }

    for (int i = 1; i < input.length(); i++) {
        if (bef == 2 && (input[i] == '5' || input[i] == '?')) {
            bef = 0;
            ans += 2;
        } else if (input[i] == '2' || input[i] == '?') {
            bef = 2;
        } else {
            bef = 0;
        }
    }

    cout << ans << endl;

    return 0;
}

