#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

typedef pair<string, int> s_i;

int main()
{
    int n;
    cin >> n;
    for (int lp = 0; lp < n; lp++) {
        int a, b, c;
        cin >> c;
        int down = 0, up = 0;
        cin >> a;
        for (int i = 1; i < c; i++) {
            cin >> b;
            if (b < a) {
                down = max(down, a-b);
            } else if (b > a) {
                up = max(up, b-a);
            }
            a = b;
        }
        cout << up << " " << down << endl;
    }
    return 0;
}



