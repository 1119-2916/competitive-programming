#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b;

    cin >> a >> b;

    a--;

    a = (a / 4) - ((a / 100) - (a / 400));
    b = (b / 4) - ((b / 100) - (b / 400));

    cout << b - a << endl;

    return 0;
}
