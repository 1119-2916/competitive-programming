#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main(void)
{
    int line[10];
    double lina[10];
    double linb[10];

    while (scanf("%d,", &line[0]) != EOF) {
        int dist = line[0];
        for (int i = 1; i < 10; i++) {
            scanf("%d,", &line[i]);
            dist += line[i];
        }
        int n, m;
        scanf("%d,%d", &n, &m);
        double d = (double)dist * (double) n / (n + m);
        dist = 0;
        for (int i = 0; i < 10; i++) {
            dist += line[i];
            if (dist >= d) {
                cout << i+1 << endl;
                break;
            }
        }
    }

    return 0;
}

            



        
