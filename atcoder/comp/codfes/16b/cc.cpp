#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>
#define INF 1010001000

using namespace std;

pair<int, int> line[200001];
int n;

int main(void)
{
    int i, j;
    long long ans = 0;
    int w, h;
    int wc, hc;

    scanf("%d %d", &w, &h);
    for (i = 0; i < w; i++) {
        cin >> line[i].first;
        line[i].second = i;
    }
    for (; i < h+w; i++) {
        cin >> line[i].first;
        line[i].second = i;
    }
    sort(line, line+w+h);

    wc = 0;
    hc = 0;
    for (i = 0; i < h+w; i++) {
        int pos = line[i].second;
        if (pos < w) {
            wc++;
            ans += (long long )(h - hc + 1) * (long long )line[i].first;
        } else {
            hc++;
            ans += (long long )(w - wc +1 ) * (long long )line[i].first;
        }
    }
    cout << ans << endl;

    return 0;
}
