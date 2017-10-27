#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    pair<string, int> data[100];
    int i = 0;
    while (cin >> data[i].first >> data[i].second) {i++;}
    sort(data, data+i);
    cout << data[0].first << '\n' << data[0].second;
    for (int j = 1; j < i; j++) {
        if (data[j-1].first != data[j].first) {
            cout << '\n' << data[j].first << '\n' << data[j].second;
        } else {
            cout << " " << data[j].second;
        }
    }
    cout << endl;
    return 0;
}

