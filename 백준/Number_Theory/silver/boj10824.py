n=int(input())
cnt=0

a,b=0,1
while (cnt != n):
    a,b=b,a+b
    cnt +=1
print(a)
