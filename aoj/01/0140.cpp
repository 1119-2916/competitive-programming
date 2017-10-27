#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

int main()
{
    int d;
    cin >> d;
    for (int data = 0; data < d; data++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            for (int i = a; i < b; i++) {
                cout << i << " ";
            }
            cout << b << endl;
        } else if (a >= 6) {
            for (int i = a; i < 10; i++) {
                cout << i << " ";
            }
            if (b <= 5) {
                for (int i = 5; i > b; i--) {
                    cout << i << " ";
                }
                cout << b << endl;
            } else {
                for (int i = 5; i >= 0; i--) {
                    cout << i << " ";
                }
                for (int i = 1; i < b; i++) {
                    cout << i << " ";
                }
                cout << b << endl;
            }
        } else {
            for (int i = a; i > b; i--) {
                cout << i << " ";
            }
            cout << b << endl;
        }
    }
    return 0;
}
