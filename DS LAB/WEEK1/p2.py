print("Looping & Conditional Branches in Python")
print()
print("Eg.1")
num=float(input("Enter a number:"))
if num>0:    
	print("Positive number")
elif num==0:    
	print("Zero")
else:    
	print("Negative number")

print()
print("Eg.2")
x=float(input("Enter a number:"))
if x<10:    
	print("Smaller")
if x>20:    
	print("Bigger")

print()
print("Eg.3")
x=5
print("Before 5")
if x==5:
	print ("this is 5")
	print("still 5")
print("After 5")
print("Before 6")
if x==6:
	print("this is 6")
print ("After 6")

print()
print("Eg.4: which will never print?")
x=float(input("Enter a number:"))
if x<20:    
	print("Below 20")
elif x<10:    
	print("Below 10")
else:    
	print("something else")

print()
print("Eg.5: Nested Decisions")
x=42
if x>1:
	print("above one")
	if x<100:
		print("less than 100")
print("All done") 

print()
print("Eg.6: Ternary operator")
age=15
b=("kid" if age<18 else "adult")
print(b)#this will print "kid"
