f=open('i','r').read().strip().split('\n')
a=[int(i)for i in f]
c=0
for i in range(len(a)):
	if a[i]>a[i-1]:c+=1
print(c)
