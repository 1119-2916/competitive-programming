#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    char data[12][12];

    while (cin >> data[0]) {
        for (int i = 1; i < 8; i++) {
            cin >> data[i];
        }
        getchar();

        bool fl = false;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (data[i][j] == '1') {
                    if (data[i][j+1] == '1' &&
                            data[i+1][j+1] == '1' &&
                            data[i+1][j] == '1') {
                        puts("A");
                        fl = true;
                    } else if (data[i+1][j] == '1' &&
                            data[i+2][j] == '1' &&
                            data[i+3][j] == '1' ) {
                        puts("B");
                        fl = true;
                    } else if (data[i][j+1] == '1' && 
                            data[i][j+2] == '1' &&
                            data[i][j+3] == '1') {
                        puts("C");
                        fl = true;
                    } else if (data[i+1][j] == '1' && 
                            data[i+1][j-1] == '1' &&
                            data[i+2][j-1] == '1') {
                        puts("D");
                        fl = true;
                    } else if (data[i][j+1] == '1' && 
                            data[i+1][j+1] == '1' &&
                            data[i+1][j+2] == '1') {
                        puts("E");
                        fl = true;
                    } else if (data[i+1][j] == '1' && 
                            data[i+1][j+1] == '1' &&
                            data[i+2][j+1] == '1') {
                        puts("F");
                        fl = true;
                    } else if (data[i+1][j] == '1' && 
                            data[i][j+1] == '1' &&
                            data[i+1][j-1] == '1') {
                        puts("G");
                        fl = true;
                    }
                }
                if (fl) {
                    break;
                }
            }
            if (fl) {
                break;
            }
        }
    }

    return 0;
}



