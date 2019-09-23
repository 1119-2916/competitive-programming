l,s=input().split()
l=int(l)
m=0
for i in range(l):
    if s[i]!='W':continue
    j=i
    while j-1>=0 and s[j-1]=='B':
        j-=1
    t=0
    if j-1>=0 and s[j-1]=='.':
        t=i-j
        while j-1>0:
            if s[j-2]=='.':break
            if s[j-2]=='B':
                t=0
                break
            j-=1
    j=i
    while j+1<l and s[j+1]=='B':
        j+=1
    if j+1<l and s[j+1]=='.':
        td=j-i
        while j+2<l:
            if s[j+2]=='.':break
            if s[j+2]=='B':
                td=0
                break
            j+=1
        t+=td
    m=max(m,t)
    #print(t)
print(m)
