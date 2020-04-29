def nod(n):
    c=0
    if n==0:
        return 1
    while n!=0:
        c=c+1
        n=n//10
    return c
def isValidIP(s):
    f=0
    l=s.split(".")
    print(l)
    if len(l)!=4:
        return False
    for i in l:
        if len(i)!=nod(int(i)):
            print(len(i),"aaya",)
            f=1
            break
        if int(i)>255 or int(i)<0:
            print("baaya")
            f=1
            break
    if f==1:
        return False
    return True
print(isValidIP("256.256.256.256"))