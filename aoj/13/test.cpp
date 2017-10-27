#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define PRIME1 99999883
#define PRIME2 99999893
#define EPS 0.00000001
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
 
int main(){
 
    int table[10][10],num[5],work[5],tmp,check,left,count = 0,tmp_count;
 
    for(int i = 0; i <= 9; i++){
        for(int k = 0; k <= 9; k++)scanf("%d",&table[i][k]);
    }

    /*
    for(int a = 0; a <= 9; a++){
        for(int b = 0; b <= 9; b++){
            for(int c = 0; c <= 9; c++){
                for(int d = 0; d <= 9; d++){
                */
int a, b, c, d;
cin >> a >> b >>c >>d;
                    num[0] = a,num[1] = b,num[2] = c,num[3] = d;
 
                    left = 0;
                    for(int i = 0; i <= 3; i++){
                        tmp = table[left][num[i]];
                        left = tmp;
                    }
                    check = left;
 
                    num[4] = check;
 
                    tmp_count = 0;
 
                    for(int not_a = 0; not_a <= 9; not_a++){
                        if(a == not_a)continue;
 
                        work[0] = not_a;
                        work[1] = num[1];
                        work[2] = num[2];
                        work[3] = num[3];
                        work[4] = num[4];
 
                        left = 0;
                        for(int i = 0; i <= 4; i++){
                            tmp = table[left][work[i]];
                            left = tmp;
                        }
                        if(left == 0){

                            rep(i, 5) {
                                cout << work[i];
                            }
                            cout << endl;
 
                            tmp_count++;
                            break;
                        }
                    }
 
                    if(tmp_count == 0){
 
                        for(int not_b = 0; not_b <= 9; not_b++){
                            if(b == not_b)continue;
 
                            work[0] = num[0];
                            work[1] = not_b;
                            work[2] = num[2];
                            work[3] = num[3];
                            work[4] = num[4];
 
                            left = 0;
                            for(int i = 0; i <= 4; i++){
                                tmp = table[left][work[i]];
                                left = tmp;
                            }
                            if(left == 0){
                            rep(i, 5) {
                                cout << work[i];
                            }
                            cout << endl;
                                tmp_count++;
                                break;
                            }
                        }
                    }
 
 
                    if(tmp_count == 0){
 
                        for(int not_c = 0; not_c <= 9; not_c++){
                            if(c == not_c)continue;
 
                            work[0] = num[0];
                            work[1] = num[1];
                            work[2] = not_c;
                            work[3] = num[3];
                            work[4] = num[4];
 
 
                            left = 0;
                            for(int i = 0; i <= 4; i++){
                                tmp = table[left][work[i]];
                                left = tmp;
                            }
                            if(left == 0){
 
                            rep(i, 5) {
                                cout << work[i];
                            }
                            cout << endl;
                                tmp_count++;
                                break;
                            }
                        }
                    }
 
                    if(tmp_count == 0){
 
                        for(int not_d = 0; not_d <= 9; not_d++){
                            if(d == not_d)continue;
 
                            work[0] = num[0];
                            work[1] = num[1];
                            work[2] = num[2];
                            work[3] = not_d;
                            work[4] = num[4];
 
                            left = 0;
                            for(int i = 0; i <= 4; i++){
                                tmp = table[left][work[i]];
                                left = tmp;
                            }
                            if(left == 0){
                            rep(i, 5) {
                                cout << work[i];
                            }
                            cout << endl;
                                tmp_count++;
                                break;
                            }
                        }
                    }
 
                    if(tmp_count == 0){
 
                        for(int not_e = 0; not_e <= 9; not_e++){
                            if(not_e == num[4])continue;
 
                            work[0] = num[0];
                            work[1] = num[1];
                            work[2] = num[2];
                            work[3] = num[3];
                            work[4] = not_e;
 
                            left = 0;
                            for(int i = 0; i <= 4; i++){
                                tmp = table[left][work[i]];
                                left = tmp;
                            }
                            if(left == 0){
                            rep(i, 5) {
                                cout << work[i];
                            }
                            cout << endl;
                                tmp_count++;
                                break;
                            }
                        }
                    }
 
                    if(tmp_count == 0){
                        for(int i = 0; i <= 3; i++){
                            if(num[i] == num[i+1])continue;
 
                            for(int k = 0; k <= 4; k++)work[k] = num[k];
                            swap(work[i],work[i+1]);
 
                            left = 0;
                            for(int k = 0; k <= 4; k++){
                                tmp = table[left][work[k]];
                                left = tmp;
                            }
                            if(left == 0){
                                tmp_count++;
                                break;
                            }
                        }
                    }
 
                    if(tmp_count > 0)count++;
                    else cout << a << b << c << d << check << endl;
                    /*
                }
            }
        }
    }
    */
 
 
    printf("%d\n",count);
 
    return 0;
}
