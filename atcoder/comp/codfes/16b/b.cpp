#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    char data[100001];
    scanf("%s", data);
    int nai = 0, gai = 0;
    for (int i = 0; i < n; i++) {
        if (data[i] == 'a' ) {
            if (nai + gai < a+b) {
                nai++;
                puts("Yes");
            } else {
                puts("No");
            }
        } else if (data[i] == 'b' ) {
            if (nai + gai < a+b && gai < b) {
                gai++;
                puts("Yes");
            } else {
                puts("No");
            }
        } else {
            puts("No");
        }
    }
    









    return 0;
}

