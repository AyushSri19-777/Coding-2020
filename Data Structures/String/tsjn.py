def call(s,p):
    c=0
    min=100000
    dict={}
    for i in p:
        if i in s:
            dict[i]=s.index(i)
            #print(dict[i])
        else:
            dict[i]=-1
            c=c+1
    #print(c)
    if c==len(p):
            print("No character present","\n")
    else:
        for i in dict:
            if dict[i]<min and dict[i]>=0:
                min=dict[i]
        print(s[min],"\n")
call("geeksforgeeks","set")
call("adcffaet","onkl")
a="AYUSHAYAY"
def Lrotate(s,n):
    return s[2:n]+s[0:2]
a="fsbcnuvqhffbsaqxwp"
b="wpfsbcnuvqhffbsaqx"
if a==Lrotate(b,len(b)):
    print(1)
else:
    print(0)
k=['1','2','3']
j=[]
for i in k:
    j.append(int(i))
print(j)
