def strstr(s,p):
    if p in s:
        return s.index(p)
    return -1
print(strstr("abcabcabcd","abcd"))
s=[]
T=int(input())
for b in range(T):
    n=int(input())
    for h in range(n):
        t=input()
        s.append(t)
    min=100000 
    f=0
    for i in s:
        if len(i)<min:
            min=len(i)
            j=i
    print("helloj",j)
    for i in range(len(j)):
        if len(j)>1:
             w=j[0:i]
        else:
            w=j[0:i+1]
        for k in s:
            if w not in k:
                f=1
                break
    if f==1:
        print(-1)
        s=[]
    else:
        print(w)
        s=[]


    