#include <bits/stdc++.h>

using namespace std;

#define int long long
#define vi vector<int>

vi prime;
vb table;

void make_prime_table()
{
    table = vb(100001, true);
    table[0] = table[1] = false;
    for (int i = 2; i < table.size(); i++) {
        if (table[i]) {
            prime.push_back(i);
            for (int j = 2; j * i < table.size(); j++) {
                table[i * j] = false;
            }
        }
    }
}



signed main()
{
    int l, r;
    for (int i = l i <= r; i++) {




    return 0;
}

