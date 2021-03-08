def bsearch(l,u,f):
	if(l>u):
		print("not found")
	else:
		mid=int((l+u)/2)
		if(x[mid]==f):
			print("found elemnt",f,"at pos",mid+1)
		elif(x[mid]>f):
			bsearch(mid,u,f)
		else:
			bsearch(l,mid,f)
x=[]
y=int(input("enter number of elements\n"))
print("enter ",y,"elements\n")
for i in range(0,y):
	x.append(int(input()))

x.sort()
print(x)
s=int(input("enter the search elemnt\n"))
a=0
bsearch(0,y-1,s)
