#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++) 

int solve(int a, int b, int c);

int main()
{
    int a, b, c;
    while (scanf("%d", &a) != EOF) {
        cin >> b >> c;
        cout << solve(a%b*10, b, c) << endl;
    }
    return 0;
}

int solve(int a, int b, int c)
{
    int ans = 0;
    
    loop(i, c) {
        ans += a/b;
        a %= b;
        a *= 10;
    }

    return ans;
}


