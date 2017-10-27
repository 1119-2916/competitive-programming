#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string a;
    long long int b;

    cin >> a >> b;

    cout << a[--b % a.length()] << endl;

    return 0;
}
