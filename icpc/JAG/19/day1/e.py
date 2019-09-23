import sys
input=sys.stdin.readline
MOD1=1010002879
MOD2=1010142139
n,m=map(int,input().split())
e=[[]for _ in range(n)]
for _ in range(m):
    a,b,x=map(int,input().split())
    e[a-1]+=(b-1,x),
    e[b-1]+=(a-1,1/x),
f=[-1]*n
while True:
    for i in range(n):
        if f[i]==-1:
            f[i]=1,1
            q=[i]
            break
    else:break
    while q:
        v=q.pop()
        cost1,cost2=f[v]
        for w,x in e[v]:
            t1=cost1*x%MOD1
            t2=cost2*x%MOD2
            if f[w]==-1:
                f[w]=t1,t2
                q+=w,
            elif f[w][0]==t1 or f[w][1]==t2:
                continue
            else:
                #print(f)
                print('No')
                exit()
print('Yes')
