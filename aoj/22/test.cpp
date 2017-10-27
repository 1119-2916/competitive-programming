#include <iostream>
#include <cstring>
using namespace std;
 
int h, w, n;
bool flg[32][32];
char t[32][32], tt[32][32];
 
void copy(char to[32][32], char from[32][32]){
  for(int i = 0; i < 32; i++){
    for(int j = 0; j < 32; j++){
      to[i][j] = from[i][j];
    }
  }
}
 
void show(){
  cout << "====\n";
  for(int i = 0; i < h; i++){
    cout << t[i] << endl;
  }
  cout << "====\n\n";
}
 
void fallBlock(){
  for(int i = h - 1; i >= 0; i--){
    for(int j = 0; j < w; j++){
      if(t[i][j] == '.'){
        int k = i;
 
        for( ; 0 <= k && t[k][j] == '.'; k--);
 
        if(k != -1){
          t[i][j] = t[k][j];
          t[k][j] = '.';
        }
      }
    }
  }
}
 
bool delBlock(){
  bool res = false;
 
  memset(flg, 0, sizeof(flg));
 
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(t[i][j] == '.') continue;
 
      if(i + n <= h){
        int k = i;
        for( ; k < h && t[k][j] == t[i][j]; k++);
        if(n <= k - i){
          for(k--; k >= i; k--) flg[k][j] = true;
          res = true;
        }
      }
      if(j + n <= w){
        int k = j;
        for( ; k < w && t[i][k] == t[i][j]; k++);
        if(n <= k - j){
          for(k--; k >= j; k--) flg[i][k] = true;
          res = true;
        }
      }
    }
  }
 
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(flg[i][j]){
        t[i][j] = '.';
      }
    }
  }
 
  return res;
}
 
bool checkDelAll(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(t[i][j] != '.'){
        return false;
      }
    }
  }
  return true;
}
 
bool solve(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w - 1; j++){
      copy(t, tt);
      if(t[i][j] == '.' && t[i][j + 1] == '.') continue;
      swap(t[i][j], t[i][j + 1]);
      fallBlock();
 
      while(true){
        bool delFlg = delBlock();
        if(!delFlg) break;
        fallBlock();
      }
 
      if(checkDelAll()) { cout << i << j << endl; return true; }
    }
  }
 
  return false;
}
 
int main(){
  while(cin >> h >> w >> n){
    for(int i = 0; i < h; i++){
      cin >> tt[i];
    }
    cout << (solve() ? "YES" : "NO") << endl;
  }
}
