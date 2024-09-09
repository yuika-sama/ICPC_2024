s=list(input())
t=list(input())

tmp=[]
n= len(s)
m= len(t)
ans=[]
for i in range(m-1):
    tmp.append(s[i])
for i in range(m-1,n):
    tmp.append(s[i])
    if tmp == t:
        ans.append(i-m+1+1)
    tmp.pop(0)
print(" ".join(map(str,ans)))