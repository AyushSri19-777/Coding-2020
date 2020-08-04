f=open("H:/C++ Programming/Data Structures/Practice/a.txt","r")
for line in f:
    #st=f.readlines()
    print(line)
f.close()
file=open("H:/C++ Programming/Data Structures/Practice/a.txt","a")
file.write("Hello motto")
