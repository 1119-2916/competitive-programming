#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

string str[] = {"null", "one pair", "two pair", "three card",
    "straight", "full house", "four card"};

int main()
{
    int hand[5];
    while (scanf("%d", &hand[0]) != EOF) {
        for (int i = 1; i < 5; i++) {
            scanf(",%d", &hand[i]);
        }
        int data[14];
        fill(data, data+14, 0);
        for (int i = 0; i < 5; i++) {
            data[hand[i]]++;
        }
        int ans = 0;
        for (int i = 1; i < 14; i++) {
            if (data[i] == 4) {
                ans = 7;
            }
            if (data[i] == 2) {
                if (ans == 2) {
                    ans = 3;
                } else if (ans == 4) {
                    ans = 6;
                } else {
                    ans = 2;
                }
            }
            if (data[i] == 3) {
                if (ans == 2) {
                    ans = 6;
                } else {
                    ans = 4;
                }
            }
        }
        sort(hand, hand+5);
        if (!ans) {
            for (int i = 1; i < 5; i++) {
                if (hand[i-1]+1 != hand[i] ) {
                    ans = 1;
                }
            }
            if (ans != 1) {
                ans = 5;
            }
            if (hand[0] == 1 && hand[1] == 10 && hand[2] == 11 &&
                    hand[3] == 12 && hand[4] == 13) {
                ans = 5;
            }
        }
        cout << str[ans-1] << endl;

    }

    return 0;
}




