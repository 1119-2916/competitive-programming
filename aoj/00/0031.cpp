#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
    int a;
    while ( scanf("%d", &a) != EOF) {
        bool fl = false;
        for (int i = 0; i < 10; i++) {
            if ((a&1) == 1) {
                if (fl) {
                    cout << " ";
                } else { 
                    fl = true;
                }
                cout << (1<<i);
            } 
            a >>= 1;
        }
        puts("");
    }
    return 0;
}
