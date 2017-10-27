#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string data;

int main()
{
    cin >> data;

    int i = 0;
    int st = 0, cnt = 0;
    while (i < (int)data.size()) {
        if (data[st] != data[i]) {
            cnt++;
            st = i;
        } 
        i++;
    }
    cout << cnt << endl;
    return 0;
}

