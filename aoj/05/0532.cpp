#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

typedef pair<string, int> s_i;

int main()
{
    for (int i = 0; i < 3; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        long at = 0, bt = 0;
        at = a * 3600 + b * 60 + c;
        cin >> a >> b >> c;
        bt = a * 3600 + b * 60 + c;
        bt -= at;
        a = bt / 3600;
        bt -= a * 3600;
        b = bt / 60;
        bt -= b * 60;
        cout << a << " " << b << " " << bt << endl;
    }
    return 0;
}
        
