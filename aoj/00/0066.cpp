#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 

string data;

int main()
{
    while (cin >> data) {
        if (data[0] == data[1] && data[1] == data[2] && data[2] != 's') {
            cout << data[0] << endl;
        } else if (data[3] == data[4] && data[4] == data[5] && data[5] != 's') {
            cout << data[3] << endl;
        } else if (data[6] == data[7] && data[7] == data[8] && data[8] != 's') {
            cout << data[6] << endl;
        } else if (data[0] == data[3] && data[3] == data[6] && data[6] != 's') {
            cout << data[0] << endl;
        } else if (data[1] == data[4] && data[4] == data[7] && data[7] != 's') {
            cout << data[1] << endl;
        } else if (data[2] == data[5] && data[5] == data[8] && data[8] != 's') {
            cout << data[2] << endl;
        } else if (data[0] == data[4] && data[4] == data[8] && data[8] != 's') {
            cout << data[0] << endl;
        } else if (data[2] == data[4] && data[4] == data[6] && data[6] != 's') {
            cout << data[2] << endl;
        } else {
            cout << "d" << endl;
        }
    }
    return 0;
}

