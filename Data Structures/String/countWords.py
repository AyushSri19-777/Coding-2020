def count():
    f1=open('demo.txt','r')
    a=f1.readline()
    s=a.split(' ')
    mydict={}
    for i in s:
        if i in mydict:
            mydict[i]=mydict[i]+1
        else:
            mydict[i]=1 

    print(mydict)
count()
#count("hello my name is hello ayush")