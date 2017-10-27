#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double v;

    while (scanf("%lf", &v) != EOF) {
        double ans = v*v + 98.0;
        for (int i = 0; i < 500; i++) {
            if (ans <= 98 * i) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}


    
