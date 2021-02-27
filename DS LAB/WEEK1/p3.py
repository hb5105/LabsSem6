import numpy as np

print("USAGE OF FOR LOOP")

print()
print("Eg.1")
for  val  in [5,4,3,2,1]:
	print(val) 
print ("Done")

print()
print("Eg.2")
stud=["Ram","Vijay","Nithya","Anu","Ramesh","Suja"]
for k in stud:
	print("Hello:", k)
print("done")

print()
print("Eg.3")
for i in range(5):
	print(i)
	if i>2:
		print("Bigger than 2")
	print("Done with i",i)

print()
print("Eg.4: Calculate factors of a number")
x=int(input("Enter a number:"))
for  i  in  range(1,x+1): 
	if x%i ==0:
		print(i)

print()
print("Eg.5: Calculate largest number in an array")
from math import *
x= [9, 41, 12, 3, 74, 15]
print(x)
Largest=-inf
for i  in  x:
	if i>Largest:
		Largest=i
print(Largest)

print()
print("Eg.6: Calculate smallest number in an array")
from math import *
x= [9, 41, 12, 3, 74, 15]
smallest=inf
for i  in  x:
	if i<smallest:
		smallest=i
print(smallest)

print()
print("Eg.7: Calculate the count, sum and average of numerical array")
x= [9, 41, 12, 3, 74, 15]
count=sum=avg=0
for  i  in  x:
	count=count+1
	sum=sum+1
avg=sum/count
print(count)
print(sum)
print(avg)

print()
print("Eg.8: Filtering in a loop (print all numbers >20)")
x= [9, 41, 12, 3, 74, 15]
for  i  in  x:
	if i>20:
		print (i)

print()
print("Eg.9: For the above problem, instead of printing the result, store the elements in a variable (object)")
x= [9, 41, 12, 3, 74, 15]
res=[]
for  i  in  x:
	if i>20:
		res.append(i)
print(res)

print()
print("Eg.10: For the above x, replace all elements <20 into zero. Store the result in different variable (object)")
y=np.zeros(len(x))
for  i  in  range(len(x)):
	if x[i]>20:
		y[i]=x[i]
print(y)