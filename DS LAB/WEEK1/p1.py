import numpy as np
print("##Assigning Values to Variables##")
counter = 100
miles = 1000.0 
name = "John"
print ("counter: ",counter) 
print ("miles: ",miles) 
print ("name: ",name) 

print("##Multiple Assignment##")
a = 5
b = 4.56
c = 1
d, e, f = 1, 2, "john" 
print("a:",a,"b:",b,"c:",c)
print("d:",d,"e:",e,"f:",f)
print("a*5:",a*5)
print("a/2:",a/2)
print("a**2:",a**2),

print("## PYTHON STRINGS ##")
s = 'Hello World!' 
print (s)
print (s[0]) 
print (s[2:5])
print (s[2:]) 
print (s * 2) 
print (s + "TEST")

print ("Updated String :", s[:6] + 'Python')

print( "My name is %s and weight is %d kg!" % ('Anitha', 55))

str = "this is string example....wow!!!"
print ("CAPITALIZE:",str.capitalize())
print("COUNT-s:",str.count('s'))
print("FIND-example:",str.find('example'))
print ("SWAPCASE:",str.swapcase())
print ("TITLE:",str.title())

str = "THIS IS STRING EXAMPLE....WOW!!!"
print ("LOWER:",str.lower())

str = "this is string example....wow!!! this is really string"
print ("REPLACE:",str.replace("is", "was"))


print("## PYTHON LISTS##")
mylist = [ 'abcd', 786 , 2.23, 'john', 70.2 ] 
tinylist = [123, 'ray'] 
print (mylist)
print (mylist[0])
print (mylist[1:3])
print (mylist[2:])
print (tinylist * 2)
print (mylist + tinylist)

mylist.append('maths')
print("APPEND:",mylist)

del mylist[2]
print("DELETE 2nd:",mylist)

print("physics in list: ",'physics' in mylist)
print("maths in list: ",'maths' in mylist)

print("LENGTH:",len(mylist))
print("COUNT maths:",mylist.count('maths'))

mylist.pop()
print("POP:",mylist)
mylist.insert (2, 'chemistry')
print("INSERT (2,chemistry):",mylist)
mylist.remove('chemistry')
print("REMOVE (chemistry):",mylist)
mylist.reverse()
print("REVERSE:",mylist)

print()


print("##TUPLES##")
tuple = ( 'abcd', 786 , 2.23, 'john', 70.2 ) 
print("TUPLE:",tuple)