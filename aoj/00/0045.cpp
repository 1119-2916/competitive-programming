#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    int a, b, sum = 0, ave = 0, cnt = 0;

    while ( scanf("%d,%d", &a, &b) != EOF ) {
        sum += a*b;
        ave += b;
        cnt++;
    }
    cout << sum << '\n' << (int)((double)ave/cnt+0.5f) << endl;

    return 0;
}
