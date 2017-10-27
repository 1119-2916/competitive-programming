#include <iostream>

using namespace std;

bool erat[50100];

int main()
{
    for (int i = 2; i*2 <= 50100; i++) {
        erat[0] = true;
        erat[1] = true;
        if (!erat[i]) {
            for (int j = 2; i*j <= 50100; j++) {
                erat[i*j] = true;
            }
        }
    }

    int n;
    while (cin >> n) {
        for (int i = n-1; i >= 0; i--) {
            if (!erat[i]) {
                cout << i << " ";
                break;
            }
        }
        for (int i = n+1; i < 50100; i++) {
            if (!erat[i]) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
