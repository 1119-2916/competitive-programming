#include<stdio.h>
int main(){
	int n,m,t;
	int a[100];
	int b[20000] = {0};
	int i,j,cnt = 0,f = 0,g=0;

	scanf("%d%d%d",&n,&m,&t);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=2;
		for(j = -m;j <= m;j++){
			b[a[i] + j] = 1;
		}
	}

	for(i = 0,g = 0;i < t;i++){
		if(b[i] == 0){
			cnt++;
g=0;
}
else{
			//if(f)cnt++;
			if(!g)f++;
g=1;
	}
}
		if(f)f--;
		
//printf("%d ",b[i]);
	

	printf("%d\n",cnt+f*2);
	return 0;
}
