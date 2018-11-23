#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;

vector<vector<int>> x(10,vector<int>(10));

int check(char s[]){
  int a=0;
  rep(j,4){
    a=x[a][s[j]-'0'];
  }
  return a;
}

signed main()
{
  rep(i,10)rep(j,10)cin>>x[i][j];
  set<int> set;
  rep(i,10000){
    char s[10]={};
    sprintf(s,"%04d",i);
    s[4]=check(s)+'0';
    rep(j,5){
      rep(k,10){
	char t[10]={};
	rep(l,5)t[l]=s[l];
	t[j]=k+'0';
	if(atoi(s)==atoi(t))continue;
	//	cout<<atoi(s)<<" "<<atoi(t)<<endl;
	char ss[10]={},tt[10]={};
	rep(l,4)ss[l]=s[l],tt[l]=t[l];
	int y=0;
	rep(l,4)y=x[y][ss[l]-'0'];
	int z=0;
	rep(l,4)z=x[z][tt[l]-'0'];
	if(x[y][s[4]-'0']==x[z][t[4]-'0']){
	  set.insert(atoi(ss));set.insert(atoi(tt));
	  //cout<<ss<<" "<<tt<<endl;
	}
      }
    }
    rep(j,4){
      char t[10];
      rep(k,5)t[k]=s[k];
      swap(t[j],t[j+1]);
      if(atoi(s)==atoi(t))continue;
      char ss[10]={},tt[10]={};
      rep(l,4)ss[l]=s[l],tt[l]=t[l];
      int y=0;
      rep(l,4)y=x[y][ss[l]-'0'];
      int z=0;
      rep(l,4)z=x[z][tt[l]-'0'];
      if(x[y][s[4]-'0']==x[z][t[4]-'0']){
	set.insert(atoi(ss));set.insert(atoi(tt));
	//	cout<<ss<<" "<<tt<<endl;
      }

    }
  }
  cout<<set.size()<<endl;
  return 0;
}
