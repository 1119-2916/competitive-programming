#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, d, p;

    cin >> a >> b >> c >> d >> p;

    int sum1, sum2;

    sum1 = a * p;

    if (p > c) {
        sum2 = b + d * (p - c);
    } else {
        sum2 = b;
    }

    cout << min(sum1, sum2) << endl;

    return 0;

}
