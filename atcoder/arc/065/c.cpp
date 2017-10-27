#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

bool solve(char *a, char *b, int len);
bool dfs(char *data);

int main()
{
    char data[100020];

    cin >> data;

    int p = 0;
    if (dfs(data)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

bool dfs(char *data)
{
    bool ret = false;
    if (data[0] == 0) {
        return true;
    }
    if (solve(data, "dream", 5)) {
        ret = (dfs(data + 5) | ret);
    }
    if (solve(data, "dreamer", 7)) {
        ret = (dfs(data + 7) | ret);
    }
    if (solve(data, "erase", 5)) {
        ret = (dfs(data + 5) | ret);
    }
    if (solve(data, "eraser", 6)) {
        ret = (dfs(data + 6) | ret);
    }

    return ret;
}



bool solve(char *a, char *b, int len)
{
    int ln = strlen(a);
    if (ln < len) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}
