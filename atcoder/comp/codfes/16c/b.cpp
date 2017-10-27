#include <iostream>
#include <algorithm>
#include <cstdio> 
#include <string>
#include <vector>

#define MAX 1010001000

using namespace std;

int a[101];

int main()
{
    int K, T;

    cin >> K >> T;

    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }

    sort(a, a+T);

    int mx = a[T-1]-1;

    for (int i = 0; i < T-1; i++) {
        mx -= a[i];
    }

    if (mx < 0) {
        cout << 0 << endl;
    } else {
        cout << mx << endl;
    }



    return 0;
}
