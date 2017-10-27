#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    while (getline(cin, s)) {
        while (s.find("the") == s.npos &&
                    s.find("this") == s.npos &&
                    s.find("that") == s.npos) {
            for (int i = 0; i < s.size(); i++) {
                if ('a' <= s[i] && s[i] <= 'y') {
                    s[i]++;
                } else if (s[i] == 'z') {
                    s[i] = 'a';
                }
            }
        }
        cout << s << endl;
    }

    return 0;
}


