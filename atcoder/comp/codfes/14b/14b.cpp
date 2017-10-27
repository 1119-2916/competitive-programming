#include <iostream>
#include <algorithm>

using namespace std;

int a;

int main()
{
    int b;
    long long sum = 0, ans;

    cin >> b >> ans;

    for (int i = 1; i <= b; i++) {
        cin >> a;
        sum += a;
        if (sum >= ans) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}



