#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int n, line[100001];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> line[i];
    }

    long long ans = line[0]-1;
    line[0] = 1;

    int max = 1;
    for (int i = 1; i < n; i++) {
        if (line[i] > max+1) {
//            cout << (line[i]-1)/(max+1) << " ";
            ans += (line[i]-1)/(max+1);
        } else if (line[i] == max+1) {
            max++;
 //           cout << "\n >> " <<  i << " " << max << " " << endl;
        }
    }

    cout << ans << endl;

    return 0;
}





