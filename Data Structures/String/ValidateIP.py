def count(m):
    n=int(m)
    if(n==0):
        return 1    
    c=0
    while n!=0:
        c=c+1
        n=n//10
    return c
def isValidIP(s):
    f=1
    a=s.split('.')
    if len(a)!=4:
        return 0
    for i in a:
        if(count(i) != len(i)):
            print(count(i),"phaasa",len(i))
            f=0
            break
        if(int(i)<0 or int(i)>255):
            print("fasa")
            f=0
            break
    return f

print(isValidIP("0.0.0.0"))