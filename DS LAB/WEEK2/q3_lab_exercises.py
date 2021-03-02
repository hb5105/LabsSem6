print("\nQuestion 1")
x=int(input("enter height "))
y=int(input("enter height "))
print("the area is ",x*y)

print("\nQuestion 2")
x=int(input("enter no1 "))
y=int(input("enter no2 "))
x=x+y
y=x-y
x=x-y
print("x is ",x,"and","y is ",y)

print("\nQuestion 3")
print("no is ",x)
if x%2==0:
	print(x,"is even")
else:
	print(x," is odd")

print("\nQuestion 4")
a=int(input("enter no1 "))
b=int(input("enter no2"))
c=int(input("enter no3 "))
a=a if a>b and a>c else b if b>a and b>c else c
print(a," is the largest of the 3")

print("\nQuestion 5")
print("while loop with else")
a=[1,2,3,4]
i=0
while(i<len(a)) :
	print(a[i],end=" ")
	i=i+1
else:
	print("index out of bounds")

print("\nQuestion 6")
x=int(input("enter the range no"))
j=2
while (j<x):
	z=2
	count=0
	while(z<j):
		if j%z==0:
			count=1
		z=z+1
	j=j+1

	if count==0:
		print(z,end=" ")
print()

print("\nQuestion 7")
a=[1,2,3,4,5,6]
print("length of array is ",len(a))
print("elements of array are ")
print(a)

a.reverse()
print(" REVERSED ARRAY IS ")
print(a)

print("\nQuestion 8")
a= tuple((1,3,5,7,9,2,4,6,8,10))
for i in  a[0:int(len(a)/2)]:
		print(i,end="	")
print()
for i in a[int(len(a)/2):len(a)]:
		print(i,end="	")
print()

print("\nQuestion 9")
a=[]
b=tuple((12,7,38,56,78))
for i in b:
	if i%2==0:
		a.append(i)
a=tuple(a)
print("new tupele ", a)

print("\nQuestion 10")
a=[11,-21,0,45,66,-93]
print("the list is ",a)
print("negative elements are: ")
for i in a:
	if i<0:
		print(i,end=" ")
print()

print("\nQuestion 11")
a=[11,-21,0,45,66,-93]
print("print neg using while")
i=0
while(i<len(a)):
	if a[i]<0:
		print(i,end=" ")
	i=i+1
print()


print("\nQuestion 12")
a=[11,-21,0,45,66,-93]
print("the list is ",a)
print("negative elements are: ")
for i in a:
	if i<0:
		print(i,end=" ")
print()
print("positive elements are: ")
for i in a:
	if i>0:
		print(i,end=" ")
print()

print("\nQuestion 13")
a=[11,-21,0,45,66,-93]
print("the list is ",a)
print("after removing all elements")
a.clear()
print(a)
print()

print("\nQuestion 14")

print("\nQuestion 15")

