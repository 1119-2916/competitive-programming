#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c) {
        int era = 0;
        if (a < 1868) {
            era = 1;
        } else if (a == 1868) {
            if (b < 9) {
                era = 1;
            } else if (b == 9) {
                if (c < 8) {
                    era = 1;
                } else {
                    era = 2;
                }
            } else {
                era = 2;
            }
        } else if (a < 1912) {
            era = 2;
        } else if (a == 1912) {
            if (b < 7) {
                era = 2;
            } else if (b == 7) {
                if (c < 30) {
                    era = 2;
                } else {
                    era = 3;
                }
            } else {
                era = 3;
            }
        } else if (a < 1926) {
            era = 3;
        } else if (a == 1926) {
            if (b < 12) {
                era = 3;
            } else if (b == 12) {
                if (c < 25) {
                    era = 3;
                } else {
                    era = 4;
                }
            } else {
                era = 4;
            }
        } else if (a < 1989) {
            era = 4;
        } else if (a == 1989) {
            if (b < 1) {
                era = 4;
            } else if (b == 1) {
                if (c < 8) {
                    era = 4;
                } else {
                    era = 5;
                }
            } else {
                era = 5;
            }
        } else {
            era = 5;
        }
        if (era == 1) {
            cout << "pre-meiji" << endl;
        } else {
            if (era == 2) {
                cout << "meiji " << a - 1867 << " ";
            } else if (era == 3) {
                cout << "taisho " << a - 1911 << " ";
            } else if (era == 4) {
                cout << "showa " << a - 1925 << " ";
            } else if (era == 5) {
                cout << "heisei " << a - 1988 << " ";
            }
            cout << b << " " << c << endl;
        }
    }
    return 0;
}



