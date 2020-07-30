def count(a):
    #f1=open('demo.txt','r')
    #a=f1.readline()
    s=a.split(' ')
    st=""
    mydict={}
    for i in s:
        if i in mydict:
            mydict[i]=mydict[i]+1
            if mydict[i]>1:
                st=st+i+str(mydict[i])+" "
        else:
            mydict[i]=1 
            st=st+i+" "

    print(st)
#count()
count("john cena john jake")