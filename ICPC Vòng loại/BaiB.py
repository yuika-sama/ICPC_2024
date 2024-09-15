n = int(input())
m = dict()
v = [1]*1000001
m[0] = 1
r = 0
for i in (1, 1e6+1):
    v[i] = v[i-1] + i
    if (v[i] == n):
        print(4)
        exit(0)
    r += m[v[i] - n]
    m[v[i]] = 1
print(r*2)