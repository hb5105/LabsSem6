x=int(input("enter no a  "))
y=int(input("enter second no "))

print("1. add \n2.sub \n3. multi \n4. div")
z=int(input('enter choice '))
if(z==1):
	print("addition = ",x+y)
elif(z==2):
	print("subtraction: ",x-y)
elif(z==3):
	print("multiplication: ",x*y)
else:
	print("division: ",x/y)

