#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char data[101][101];

pair<int, int> search(pair<int, int> p);

int main()
{
    int n, m;

    while (cin >> n >> m, n || m) {
        for (int i = 0; i < n; i++) {
            cin >> data[i];
        }
        bool c[101][101] = {false};
        pair<int, int> pos = make_pair(0, 0);
        while (1) {
            pair<int, int> np = search(pos);
            if (np == pos) {
                cout << pos.second << " " << pos.first << endl;
                break;
            } else {
                pos = np;
            }
            if (c[pos.first][pos.second]) {
                puts("LOOP");
                break;
            } else {
                c[pos.first][pos.second] = true;
            }
        }
    }
    return 0;
}

pair<int, int> search(pair<int, int> p)
{
    if (data[p.first][p.second] == 'v') {
        return make_pair(p.first+1, p.second);
    } else if (data[p.first][p.second] == '^') {
        return make_pair(p.first-1, p.second);
    } else if (data[p.first][p.second] == '>') {
        return make_pair(p.first, p.second+1);
    } else if (data[p.first][p.second] == '<') {
        return make_pair(p.first, p.second-1);
    } else {
        return p;
    }
}
