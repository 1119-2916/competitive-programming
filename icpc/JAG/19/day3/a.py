n=int(input())
*a,=map(int,input().split())
o=e=0
for i in a:
    if i%2:
        o+=1
    else:
        e+=1
if not o or not e:
    print(0)
elif o%2:
    print(n-1)
else:
    print(n-2)
